#include "Entity.h"

class Creature;

#pragma once
class Item : public Entity
{
public:
	Item(const string& _name, const string& _description, Entity* _parent);

	void Lock(Creature* _protector);
	string GetProtectorName();

	bool locked;
	Creature* protector;
};

