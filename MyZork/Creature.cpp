#include "Creature.h"
#include "Room.h"

Creature::Creature(const string& _name, const string& _description, Room* _location) :
Entity(_name, _description) {
	location = _location;
}
