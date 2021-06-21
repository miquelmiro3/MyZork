#include "Exit.h"
#include "Room.h"
#include "Item.h"

Exit::Exit(const string& _name, const string& _description, string _direction, string _reverseDirection, Room* _source, Room* _destination) :
Entity(_name, _description) {
	type = roomExit;

	direction = _direction;
	reverseDirection = _reverseDirection;
	source = _source;
	destination = _destination;

	source->exits.push_back(this);
	destination->exits.push_back(this);

	locked = false;
	key = NULL;
}

void Exit::Lock(Item* _key) {
	locked = true;
	key = _key;
}

bool Exit::SameDirection(Room* _room, const string _direction) {
	if (_room == source && _direction == direction) return true;
	if (_room == destination && _direction == reverseDirection) return true;
	return false;
}