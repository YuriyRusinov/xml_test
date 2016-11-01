#ifndef _Article_H
#define _Article_H

#include <string>
#include <vector>

#include "author.h"

using std::vector;

class Article
{
public:
    Article (const std::string& title=std::string(), const vector<Author>& authors=vector<Author>());
    Article (const Article& A);
    ~Article (void);

    std::string getTitle (void) const;
    void setTitle (std::string title);

    const vector<Author>& getAuthors (void) const;
    vector<Author>& authors (void);
    void setAuthors (const vector<Author>& authList);

private:
    std::string a_title;
    vector<Author> author_list;
};

#endif
