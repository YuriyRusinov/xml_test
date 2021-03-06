#include "article.h"

Article :: Article (const std::string& title, const vector<Author>& authors)
    : a_title (title),
    author_list (authors)
{
}

Article :: Article (const Article& A)
    : a_title (A.a_title),
    author_list (A.author_list)
{
}

Article :: ~Article (void)
{
}

std::string Article :: getTitle (void) const
{
    return a_title;
}

void Article :: setTitle (std::string title)
{
    a_title = title;
}

const vector<Author>& Article :: authors (void) const
{
    return author_list;
}

vector<Author>& Article :: authors (void)
{
    return author_list;
}

void Article :: setAuthors (const vector<Author>& authList)
{
    author_list = authList;
}

ostream& operator<< (ostream& out, const Article& AR)
{
    out << AR.a_title << std::endl;
    int n = AR.author_list.size ();
    for (int i=0; i<n; i++)
    {
        Author a = AR.author_list[i];
        out << "    " << a << std::endl;
    }
    return out;
}
