#include "Item.h"
#include "Creature.h"

Item::Item(const string& _name, const string& _description, Entity* _parent) :
Entity(_name, _description, _parent) {
	type = item;

	locked = false;
	protector = NULL;
}

void Item::Lock(Creature* _protector) {
	locked = true;
	protector = _protector;

	_protector->protecting = this;
}

string Item::GetProtectorName() {
	return protector->name;
}