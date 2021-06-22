#include "Item.h"
#include "Creature.h"

Item::Item(const string& _name, const string& _description, ItemType _itemType, Entity* _parent) :
Entity(_name, _description, _parent) {
	type = item;

	itemType = _itemType;
	attack = 0;
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