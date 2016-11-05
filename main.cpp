#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include <tinyxml2.h>

#include "article.h"
#include "author.h"
#include "imatrix.h"

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;

using tinyxml2::XMLDocument;
using tinyxml2::Whitespace;
using tinyxml2::XMLError;
using tinyxml2::XMLElement;

int main (int argc, char* argv[])
{
    if (argc <= 1)
    {
        cerr << "You have to set xml-file name as argument" << endl;
        return 1;
    }
    string xml_file (argv[1]);
    ifstream xml_stream (xml_file.c_str());
    if (!xml_stream || !xml_stream.good())
    {
        cerr << "File " << xml_file << " does not exist" << endl;
        return 2;
    }
    XMLDocument * docXml = new XMLDocument (true, Whitespace::PRESERVE_WHITESPACE);
    XMLError ier = docXml->LoadFile (xml_file.c_str());
    if (ier != tinyxml2::XML_NO_ERROR)
    {
        cerr << "Invalid xml file, error code=" << ier << ' ' << docXml->GetErrorStr1 () << endl;
        return ier;
    }
    XMLElement * rootElem = docXml->RootElement ();
    cout << rootElem->Name () << endl;
    XMLElement * articleElem = rootElem->FirstChildElement ();
    vector<Article> articles;
    vector<Author> AllAuthors;
    while (articleElem)
    {
        //cout << articleElem->Name () << endl;
        Article a;
        XMLElement * telem = articleElem->FirstChildElement ();
        //cout << telem->Name () << " " << telem->GetText () << endl;
        XMLElement * authListElem = telem->NextSiblingElement ();
        //cout << authListElem->Name () << endl;
        if (string (telem->Name()).compare ("ArticleTitle") != 0 ||
            string (authListElem->Name ()).compare ("AuthorList") != 0)
        {
            cerr << "Invalid elements" << endl;
            return 3;
        }
        if (string (telem->Name()).compare ("ArticleTitle") == 0)
        {
            string title (telem->GetText ());
            a.setTitle (title);
        }
        XMLElement * authElement = authListElem->FirstChildElement ();
        vector<Author> authors;
        for (; authElement; authElement = authElement->NextSiblingElement ())
        {
            if (string (authElement->Name ()).compare ("Author") != 0)
            {
                cerr << "Invalid elements" << endl;
                return 3;
            }
            string last_name;
            string first_name;
            string initials;
            XMLElement * aNameElem = authElement->FirstChildElement ();
            //cout << aNameElem->Name() << endl;
            if (string(aNameElem->Name()).compare ("LastName") == 0)
                last_name = aNameElem->GetText ();
            else if (string(aNameElem->Name()).compare ("ForeName") == 0)
                first_name = aNameElem->GetText ();
            else if (string(aNameElem->Name()).compare ("Initials") == 0)
                initials = aNameElem->GetText ();
            else
            {
                cerr << "Invalid authors " << aNameElem->Name() << endl;
                return 3;
            }
            XMLElement * aFNameElem = aNameElem->NextSiblingElement ();
            if (string(aFNameElem->Name()).compare ("LastName") == 0)
                last_name = aFNameElem->GetText ();
            else if (string(aFNameElem->Name()).compare ("ForeName") == 0)
                first_name = aFNameElem->GetText ();
            else if (string(aFNameElem->Name()).compare ("Initials") == 0)
                initials = aFNameElem->GetText ();
            else
            {
                cerr << "Invalid authors " << aFNameElem->Name() << endl;
                return 3;
            }
            XMLElement * aINameElem = aFNameElem->NextSiblingElement ();
            if (string(aINameElem->Name()).compare ("LastName") == 0)
                last_name = aINameElem->GetText ();
            else if (string(aINameElem->Name()).compare ("ForeName") == 0)
                first_name = aINameElem->GetText ();
            else if (string(aINameElem->Name()).compare ("Initials") == 0)
                initials = aINameElem->GetText ();
            else
            {
                cerr << "Invalid authors " << aINameElem->Name() << endl;
                return 3;
            }
            Author Auth (last_name, first_name, initials);
            authors.push_back (Auth);
            if (std::count (AllAuthors.begin(), AllAuthors.end(), Auth) == 0)
            {
                AllAuthors.push_back (Auth);
                std::sort (AllAuthors.begin(), AllAuthors.end());
            }
        }
        a.setAuthors (authors);
        //cout << authElement->Name () << endl;
/*        while (elem && !elem->NoChildren ())
        {
            cout << elem->Name () << endl;
            elem = elem->NextSiblingElement ();
        }
*/
        cout << a << std::endl;
        articles.push_back (a);
        articleElem = articleElem->NextSiblingElement ();
    }
    delete docXml;
    //cout << AllAuthors.size () << endl;
    int nAuth = AllAuthors.size ();
    IMatrix authMatr (nAuth, nAuth, 0);
    int nAr = articles.size ();
    for (int i=0; i<nAr; i++)
    {
        Article a = articles[i];
        vector<Author> auths = a.authors ();
        int na = auths.size ();
        vector<int> prev_pos;
        for (int j=0; j<na; j++)
        {
            Author a = auths[j];
            std::vector<Author>::iterator pa = std::lower_bound (AllAuthors.begin(), AllAuthors.end(), a);
            int numAuth = pa - AllAuthors.begin();
            authMatr (numAuth, numAuth)++;
            for (unsigned int jj=0; jj<prev_pos.size(); jj++)
            {
                //cerr << prev_pos[jj] << numAuth;
                authMatr (prev_pos[jj], numAuth)++;
                authMatr (numAuth, prev_pos[jj])++;
            }
            prev_pos.push_back (numAuth);
        }
    }
    for (int i=0; i<nAuth; i++)
    {
        for (int j=0; j<nAuth; j++)
            cout << authMatr (i, j) << ' ';
        cout << endl;
    }
    return 0;
}
