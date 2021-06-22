#include "Creature.h"
#include "Room.h"
#include "Item.h"

Creature::Creature(const string& _name, const string& _description, int _health, int _attack, Room* _location) :
Entity(_name, _description, _location) {
	type = creature;

	health = _health;
	maxHealth = _health;
	attack = _attack;
	location = _location;
	protecting = NULL;
}

void Creature::Die() {
	protecting->locked = false;
	protecting->protector = NULL;

	location->contains.remove(this);

	delete this;
}