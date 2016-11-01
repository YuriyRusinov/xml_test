#include "author.h"

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
