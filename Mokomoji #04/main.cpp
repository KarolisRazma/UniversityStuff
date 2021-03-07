#include "VideoGame.h"
#include <iostream>
#include <string>

using namespace std;
using namespace Game;

int main()
{
    try
    {
        VideoGame example_1;
        VideoGame example_2;
        VideoGame example_3("Runescape", "MMORPG", 2001, true);

        example_1.setName("Lineage II");
        example_1.setGenre("MMORPG");
        example_1.setReleaseYear(2003);
        example_1.setMultiplayer(true);

        cout << example_1.toString() << endl;

        ++example_1;

        cout << example_1.toString() << endl;

        cin >> example_2;

        cout << (example_1 < example_2);
        cout << (example_1 > example_2);
        cout << (example_1 >= example_2);
        cout << (example_1 <= example_2);
        cout << (example_1 == example_2);
        cout << (example_1 != example_2) << endl;

        cout << example_2.toString() << endl;
        cout << example_3.toString() << endl;

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
