#include <iomanip>
#include "author.h"

using std::setw;

Author :: Author (const string& lastname, const string& forename, const string& initials)
    : LastName (lastname),
    ForeName (forename),
    Initials (initials)
{
}

string Author :: getLastName (void) const
{
    return LastName;
}

void Author :: setLastName (const string& lName)
{
    LastName = lName;
}

string Author :: getForeName (void) const
{
    return ForeName;
}

void Author :: setForeName (const string& fName)
{
    ForeName = fName;
}

string Author :: getInitials (void) const
{
    return  Initials;
}

void Author :: setInitials (const string& initials)
{
     Initials = initials;
}

bool Author :: operator< (const Author& A) const
{
    if (LastName != A.LastName)
        return LastName < A.LastName;
    else if (ForeName != A.ForeName)
        return ForeName < A.ForeName;
    else
        return Initials < A.Initials;
}

bool Author :: operator== (const Author& A) const
{
    return LastName == A.LastName && ForeName == A.ForeName && Initials == A.Initials;
}

bool Author :: operator!= (const Author& A) const
{
    return !(*this == A);
}

ostream& operator<< (ostream& out, const Author& A)
{
    out << setw (6) << A.LastName << "," << std::endl << setw (6) << A.ForeName ;//<< std::endl;// << A.Initials;
    return out;
}
