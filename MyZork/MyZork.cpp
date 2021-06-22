#include <iostream>
#include <string>
#include <vector>

#include "World.h"

using namespace std;

vector<string> String2Vector(const string& _s) {
    vector<string> _result;
    string _aux = "";
    for (int i = 0; i < _s.size(); i++) {
        if (_s[i] == ' ' && _aux != "") {
            _result.push_back(_aux);
            _aux = "";
        }
        else _aux += _s[i];
    }
    if (_aux != "") _result.push_back(_aux);

    return _result;
}


int main()
{
    World _world;
    string _input;
    vector<string> _action;

    cout << "Welcome to MyZork!!" << endl;
    cout << "Use help or h anytime to see all possible comands." << endl;
    cout << " While you were looking for the lost treasure in the forest, the ground collapsed and you fell into an underground chamber." << endl;

    while (1) {
        cout << endl << ">";

        getline(cin, _input);
        _action = String2Vector(_input);

        if (!_world.Update(_action)) cout << " That's not a verb I recognise." << endl;

        if (_world.quit) break;
    }
    getline(cin, _input);
}
