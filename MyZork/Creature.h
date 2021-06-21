#include "Entity.h"

class Room;
class Item;

#pragma once
class Creature : public Entity
{
public:
	Creature(const string& _name, const string& _description, Room* _location);

	Room* location;
	Item* protecting;
};

