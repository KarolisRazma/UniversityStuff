#include "Check.h"
#include <stdexcept>

using std::string;
using std::invalid_argument;

#define CAPACITY 9
#define FIRST_GAME_RELEASE_YEAR 1958
#define CURRENT_YEAR 2021

namespace Check
{
    static string possibleGenres[CAPACITY] =
    {
        "Action", "FPS", "MMORPG", "Simulation", "Sports", "Adventure", "Strategy", "Sandbox", "RPG"
    };

    bool checkGenre(string &genre)
    {
        for(int i = 0; i < CAPACITY; ++i)
        {
            if(genre == possibleGenres[i])
                return true;
        }
        return false;
    }

    bool checkName(string &name)
    {
        int nLength = name.length();
        for(int i = 0; i < nLength; ++i)
        {
            if((!isalpha(name[i]) && name[i] != ' ') || !(isupper(name[0])) || name.length() < 3)
            {
                return false;
            }
        }
        return true;
    }

    bool checkReleaseYear(unsigned int &date)
    {
        if(date >= FIRST_GAME_RELEASE_YEAR && date <= CURRENT_YEAR)
            return true;
        else
            return false;
    }
}

