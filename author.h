#ifndef _Author_H
#define _Author_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Author
{
public:
    Author (const string& lastname=string(), const string& forename=string(), const string& initials=string());

    string getLastName (void) const;
    void setLastName (const string& lName);
    
    string getForeName (void) const;
    void setForeName (const string& fName);

    string getInitials (void) const;
    void setInitials (const string& initials);

    friend ostream& operator<< (ostream& out, const Author& A);
    bool operator< (const Author& A) const;
    bool operator== (const Author& A) const;
    bool operator!= (const Author& A) const;

private:
    string LastName;
    string ForeName;
    string Initials;
};

#endif
