#include <iostream>
#include <string>
#include <vector>

#include "World.h"

using namespace std;

int main()
{
    World world;
    string input;

    cout << "Welcome MyZork!" << endl;

    while (1) {
        cout << ">";

        getline(cin, input);

        cout << input << endl;
    }
}
