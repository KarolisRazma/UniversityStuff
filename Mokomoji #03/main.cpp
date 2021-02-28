#include "VideoGame.hpp"

using namespace std;
using namespace game;

int main()
{
    try
    {
        // example 1
        VideoGame example_1;
        example_1.setName("Lineage II");
        example_1.setGenre("MMORPG");
        example_1.setReleaseDate(2003);
        example_1.setMultiplayer(true);

        cout << example_1.toString() << endl;

        // example 2
        VideoGame example_2[3];

        example_2[0].setName("GTA V");
        example_2[0].setGenre("Action");
        example_2[0].setReleaseDate(2013);
        example_2[0].setMultiplayer(true);

        cout << example_2[0].toString() << endl;

        example_2[1].setName("Minecraft");
        example_2[1].setGenre("Sandbox");
        example_2[1].setReleaseDate(2011);
        example_2[1].setMultiplayer(true);

        cout << example_2[1].toString() << endl;

        example_2[2].setName("Terraria");
        example_2[2].setGenre("Adventure");
        example_2[2].setReleaseDate(2011);
        example_2[2].setMultiplayer(true);

        cout << example_2[2].toString() << endl;

        // example 3
        VideoGame *example_3 = new VideoGame[2];

        example_3[0].setName("Euro Truck Simulator");
        example_3[0].setGenre("Simulation");
        example_3[0].setReleaseDate(2012);
        example_3[0].setMultiplayer(true);

        cout << example_3[0].toString() << endl;

        example_3[1].setName("Stronghold");
        example_3[1].setGenre("Strategy");
        example_3[1].setReleaseDate(2001);
        example_3[1].setMultiplayer(false);

        cout << example_3[1].toString() << endl;

        delete[] example_3;

        // example 4
        VideoGame *example_4 = new VideoGame;

        example_4->setName("Runescape");
        example_4->setGenre("error"); // this line will throw exception
        example_4->setReleaseDate(2001);
        example_4->setMultiplayer(true);

        cout << example_4->toString() << endl;

        delete example_4;
    }
    catch(invalid_argument& error)
    {
        cerr << "Exception: invalid argument - " << error.what() << endl;
    }
    catch(...)
    {
        cerr << "Exception: unknown exception catched, something's wrong!" << endl;
    }

    return 0;
}
