#include "VideoGame.h"
#include "Check.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

using std::string;
using std::endl;
using std::invalid_argument;
using std::stringstream;
using std::setw;
using std::left;
using std::istream;
using std::ostream;

using namespace Check;

#define INVALID_NAME "Wrong game name!"
#define INVALID_GENRE "Wrong genre!"
#define INVALID_YEAR "Wrong release year!"
#define INVALID_MULTIPLAYER "Wrong multiplayer value!"

#define DEFAULT_NAME "Not found"
#define DEFAULT_GENRE "Not found"
#define DEFAULT_RELEASE_YEAR 404

namespace Game
{
    int VideoGame::gamesCounter = 1;

    VideoGame::VideoGame()
    {
        setGameID();
        setName(DEFAULT_NAME);
        setGenre(DEFAULT_GENRE);
        setReleaseYear(DEFAULT_RELEASE_YEAR);
        setMultiplayer(false);
        ++gamesCounter;
    }

    VideoGame::VideoGame(const string n, const string g, unsigned int rYear, bool isMultiP)
    {
        setGameID();
        setName(n);
        setGenre(g);
        setReleaseYear(rYear);
        setMultiplayer(isMultiP);
        ++gamesCounter;
    }

    VideoGame::~VideoGame()
    {

    }

    // start of setters
    void VideoGame::setName(string nameOfGame)
    {
        if(checkName(nameOfGame) || nameOfGame == DEFAULT_NAME)
            name = nameOfGame;
        else
            throw invalid_argument(INVALID_NAME);
    }

    void VideoGame::setGenre(string genreOfGame)
    {
        if(checkGenre(genreOfGame) || genreOfGame == DEFAULT_GENRE)
            genre = genreOfGame;
        else
            throw invalid_argument(INVALID_GENRE);
    }

    void VideoGame::setReleaseYear(unsigned int year)
    {
        if(checkReleaseYear(year) || year == DEFAULT_RELEASE_YEAR)
            releaseYear = year;
        else
            throw invalid_argument(INVALID_YEAR);
    }

    void VideoGame::setMultiplayer(bool isOnline)
    {
        if(isOnline)
            isMultiplayer = isOnline;
        else if(isOnline == false)
            isMultiplayer = isOnline;
        else
            throw invalid_argument(INVALID_MULTIPLAYER);
    }

    void VideoGame::setGameID()
    {
        gameID = gamesCounter;
    }
    // end of setters

    // start of getters
    string VideoGame::getName() const
    {
        return name;
    }

    string VideoGame::getGenre() const
    {
        return genre;
    }

    unsigned int VideoGame::getReleaseYear() const
    {
        return releaseYear;
    }

    bool VideoGame::getIsMultiplayer() const
    {
        return isMultiplayer;
    }

    unsigned VideoGame::getID() const
    {
        return gameID;
    }
    // end of getters

    string VideoGame::toString() const
    {
        stringstream ss;
        ss << getID() << ") Video game: " << setw(20) << left << getName() << "\t" << " Genre: " << setw(10) << left << getGenre() << "\t";
        ss << " Release date: " << getReleaseYear() << "\t" << " Multiplayer: " << (getIsMultiplayer() ? "Yes" : "No") << "\t" << endl;
        return ss.str();
    }

    bool VideoGame::operator ==(const VideoGame& game)
    {
        if(this->getReleaseYear() == game.getReleaseYear())
            return true;
        else
            return false;
    }

    bool VideoGame::operator !=(const VideoGame& game)
    {
        return !(*this == game);
    }

    bool VideoGame::operator <(const VideoGame& game)
    {
        return !(*this >= game);
    }

    bool VideoGame::operator <=(const VideoGame& game)
    {
        if(this->getReleaseYear() > game.getReleaseYear())
            return false;
        else
            return true;
    }

    bool VideoGame::operator >(const VideoGame& game)
    {
        return !(*this <= game);
    }

    bool VideoGame::operator >=(const VideoGame& game)
    {
        if(this->getReleaseYear() < game.getReleaseYear())
            return false;
        else
            return true;
    }

    VideoGame VideoGame::operator++()
    {
        unsigned int year = this->getReleaseYear();
        this->setReleaseYear(++year);
        return *this;
    }

    VideoGame VideoGame::operator++(int)
    {
        VideoGame temp = *this;
        unsigned int year = this->getReleaseYear();
        this->setReleaseYear(++year);
        return temp;
    }

    ostream& operator <<(ostream& output, const VideoGame& game)
    {
        output << game.toString();
        return output;
    }

    istream& operator >>(istream& input, VideoGame& game)
    {
        VideoGame tempGame;
        input >> tempGame.name;
        input >> tempGame.genre;
        input >> tempGame.releaseYear;
        input >> tempGame.isMultiplayer;
        game.setName(tempGame.name);
        game.setGenre(tempGame.genre);
        game.setReleaseYear(tempGame.releaseYear);
        game.setMultiplayer(tempGame.isMultiplayer);

        return input;
    }
}
