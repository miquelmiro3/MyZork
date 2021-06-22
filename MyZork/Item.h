#include "Entity.h"

class Creature;

#pragma once
enum ItemType {
	equipable,
	upgrade,
	key
};

class Item : public Entity
{
public:
	Item(const string& _name, const string& _description, ItemType _itemType, Entity* _parent);

	void Lock(Creature* _protector);
	string GetProtectorName();

	ItemType itemType;
	int attack;
	bool locked;
	Creature* protector;
};

