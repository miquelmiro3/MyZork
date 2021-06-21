#include "Room.h"
#include "Exit.h"

Room::Room(const string& _name, const string& _description, Entity* _parent) :
Entity(_name, _description, _parent) {}

Exit* Room::FindExit(const string _direction) {
	for (list<Exit*>::iterator _it = exits.begin(); _it != exits.end(); _it++) {
		if ((*_it)->SameDirection(this, _direction)) return (*_it);
	}
	return NULL;
}