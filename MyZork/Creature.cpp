#include "Creature.h"
#include "Room.h"
#include "Item.h"

Creature::Creature(const string& _name, const string& _description, Room* _location) :
Entity(_name, _description, _location) {
	type = creature;

	location = _location;
	protecting = NULL;
}
