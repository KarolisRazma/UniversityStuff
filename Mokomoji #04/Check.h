#ifndef CHECK_H
#define CHECK_H

#include <string>

using std::string;

namespace Check
{
    bool checkGenre(string &genre);
    bool checkName(string &name);
    bool checkReleaseYear(unsigned int &date);
}

#endif // CHECK_H
