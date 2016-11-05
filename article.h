#ifndef _Article_H
#define _Article_H

#include <string>
#include <vector>
#include <iostream>

#include "author.h"

using std::vector;
using std::ostream;

class Article
{
public:
    Article (const std::string& title=std::string(), const vector<Author>& authors=vector<Author>());
    Article (const Article& A);
    ~Article (void);

    std::string getTitle (void) const;
    void setTitle (std::string title);

    const vector<Author>& authors (void) const;
    vector<Author>& authors (void);
    void setAuthors (const vector<Author>& authList);

    friend ostream& operator<< (ostream& out, const Article& AR);

private:
    std::string a_title;
    vector<Author> author_list;
};

#endif
