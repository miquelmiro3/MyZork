#include <iostream>
#include "Room.h"
#include "Exit.h"
#include "Item.h"

Room::Room(const string& _name, const string& _description, Entity* _parent) :
Entity(_name, _description, _parent) {
	type = room;
}

Exit* Room::FindExit(const string _direction) {
	for (list<Exit*>::iterator _it = exits.begin(); _it != exits.end(); _it++) {
		if ((*_it)->SameDirection(this, _direction)) return (*_it);
	}
	return NULL;
}

void Room::Examine() {
	if (contains.size() <= 0) {
		cout << " There is nothing of interest in this room." << endl;
		return;
	}
	cout << " You see a:" << endl;
	for (list<Entity*>::iterator _it = contains.begin(); _it != contains.end(); _it++) {
		cout << "  " << (*_it)->name << endl;
	}
}

bool Room::Examine(const string& _entity) {
	for (list<Entity*>::iterator _it = contains.begin(); _it != contains.end(); _it++) {
		if ((*_it)->name == _entity) {
			cout << " " << (*_it)->description << endl;
			return true;
		}
	}
	return false;
}

Item* Room::FindItem(const string& _item) {
	for (list<Entity*>::iterator _it = contains.begin(); _it != contains.end(); _it++) {
		if ((*_it)->name == _item) {
			if ((*_it)->type == item) return (Item*)(*_it);
			else return NULL;
		}
	}
	return NULL;
}