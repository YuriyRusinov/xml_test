#include <iostream>
#include <string>
#include <fstream>

#include <tinyxml2.h>

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
//    string xml_line;
/*    while (getline (xml_stream, xml_line))
    {
    }
*/
    XMLElement * rootElem = docXml->RootElement ();
    cout << rootElem->Name () << endl;
    XMLElement * articleElem = rootElem->FirstChildElement ();
    cout << articleElem->Name () << endl;
    XMLElement * elem = articleElem->FirstChildElement ();
    while (elem && !elem->NoChildren ())
    {
        cout << elem->Name () << endl;
        elem = elem->NextSiblingElement ();
    }
    delete docXml;
    return 0;
}
