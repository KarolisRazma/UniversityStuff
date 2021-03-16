#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <string>

using std::string;
using std::istream;
using std::ostream;

namespace Game
{
    class VideoGame
    {
        private:
            class InnerVideoGame;
            InnerVideoGame *ptr;
            friend class InnerVideoGame;

        public:
            VideoGame();
            VideoGame(const string& n, const string& g, unsigned int rYear, bool isMultiP);
            ~VideoGame();

            // setters
            // set everything
            void setGame(const string& n, const string& g, unsigned int rYear, bool isMultiP);
            // set one at the time
            void setName(const string& nameOfGame);
            void setGenre(const string& genreOfGame);
            void setReleaseYear(unsigned int year);
            void setMultiplayer(bool isOnline);
            void setGameID();

            // getters
            string getName() const;
            string getGenre() const;
            unsigned int getReleaseYear() const;
            bool getIsMultiplayer() const;
            unsigned int getID() const;

            // other methods
            string toString() const;
            bool operator ==(const VideoGame& game);
            bool operator !=(const VideoGame& game);
            bool operator <(const VideoGame& game);
            bool operator <=(const VideoGame& game);
            bool operator >(const VideoGame& game);
            bool operator >=(const VideoGame& game);

            VideoGame& operator =(const VideoGame& game);

            VideoGame& operator++();
            VideoGame operator++(int);

            friend ostream& operator <<(ostream& output, const VideoGame& game);
            friend istream& operator >>(istream& input, VideoGame& game);
    };
}

#endif // VIDEOGAME_H
