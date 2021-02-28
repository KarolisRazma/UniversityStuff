#include "VideoGame.hpp"

int game::VideoGame::gamesCounter = 1;

game::VideoGame::VideoGame()
{
    gameID = gamesCounter;

    name = DEFAULT_NAME;
    genre = DEFAULT_GENRE;
    releaseDate = DEFAULT_RELEASE_DATE;
    isMultiplayer = false;

    ++gamesCounter;
}

game::VideoGame::~VideoGame()
{

}

// start of setters
void game::VideoGame::setName(string nameOfGame)
{
    if(checkName(nameOfGame))
        name = nameOfGame;
    else
        throw invalid_argument("Wrong game name!");
}

void game::VideoGame::setGenre(string genreOfGame)
{
    if(checkGenre(genreOfGame))
        genre = genreOfGame;
    else
        throw invalid_argument("Wrong genre!");
}

void game::VideoGame::setReleaseDate(unsigned int yearOfRelease)
{
    if(checkReleaseDate(yearOfRelease))
        releaseDate = yearOfRelease;
    else
        throw invalid_argument("Wrong release year!");
}

void game::VideoGame::setMultiplayer(bool isOnline)
{
    if(isOnline)
        isMultiplayer = isOnline;
    else if(isOnline == false)
        isMultiplayer = isOnline;
    else
        throw invalid_argument("Wrong multiplayer value!");
}
// end of setters

// start of getters
string game::VideoGame::getName()
{
    return name;
}

string game::VideoGame::getGenre()
{
    return genre;
}

unsigned int game::VideoGame::getReleaseDate()
{
    return releaseDate;
}

bool game::VideoGame::getIsMultiplayer()
{
    return isMultiplayer;
}
// end of getters

string game::VideoGame::toString()
{
    stringstream ss;
    ss << gameID << ") Video game: " << setw(20) << left << getName() << "\t" << " Genre: " << setw(10) << left << getGenre() << "\t" << " Release date: " << getReleaseDate() << "\t" << " Multiplayer: " << checkIfMultiplayer() << "\t" << endl;
    return ss.str();
}

string game::VideoGame::checkIfMultiplayer()
{
    if(isMultiplayer)
        return "Yes";
    else
        return "No";
}

bool game::VideoGame::checkGenre(string genre)
{
    for(int i = 0; i < CAPACITY; ++i)
    {
        if(genre == possibleGenres[i])
            return true;
    }
    return false;
}

bool game::VideoGame::checkName(string name)
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

bool game::VideoGame::checkReleaseDate(unsigned int date)
{
    if(date >= FIRST_GAME_RELEASE_DATE && date <= CURRENT_YEAR)
        return true;
    else
        return false;
}
