#include <iostream>
#include "Player.h"
#include "Room.h"
#include "Exit.h"

Player::Player(Room* _location) {
	location = _location;
}

void Player::Move(const string& _direction) {
	Exit* _exit = location->FindExit(_direction);

	if (_exit == NULL) cout << "You can't do that." << endl;
	else {
		if (_exit->locked) cout << "The door is closed." << endl;
		else {
			Room* _newRoom = (location == _exit->source) ? _exit->destination : _exit->source;
			cout << _newRoom->description << endl;
			location = _newRoom;
		}
	}
}