#ifndef VIDEOGAME_HPP
#define VIDEOGAME_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

#define CAPACITY 9
#define FIRST_GAME_RELEASE_DATE 1958
#define CURRENT_YEAR 2021

#define DEFAULT_NAME "Not found"
#define DEFAULT_GENRE "Not found"
#define DEFAULT_RELEASE_DATE 404

using namespace std;

namespace game
{
    class VideoGame
    {
        private:
            string name;
            string genre;
            unsigned int releaseDate;
            bool isMultiplayer;
            static int gamesCounter;
            unsigned int gameID;

            const string possibleGenres[CAPACITY]
            {
                "Action", "FPS", "MMORPG", "Simulation", "Sports", "Adventure", "Strategy", "Sandbox", "RPG"
            };

        public:
            VideoGame();
            ~VideoGame();

            // setters
            void setName(string nameOfGame);
            void setGenre(string genreOfGame);
            void setReleaseDate(unsigned int yearOfRelease);
            void setMultiplayer(bool isOnline);

            // getters
            string getName();
            string getGenre();
            unsigned int getReleaseDate();
            bool getIsMultiplayer();

            // other methods
            string toString();

        private:
            // methods to check input
            string checkIfMultiplayer();
            bool checkGenre(string genre);
            bool checkName(string name);
            bool checkReleaseDate(unsigned int date);

    };
}

#endif // VIDEOGAME_HPP
