#include "Entity.h"

class Room;
class Item;

#pragma once
class Exit : public Entity
{
public:
	Exit(const string& _name, const string& _description, const string _direction, const string _reverseDirection, Room* _source, Room* _destination);

	void Lock(Item* _key);
	bool SameDirection(Room* _room, const string _direction);

	string direction;
	string reverseDirection;
	Room* source;
	Room* destination;
	bool locked;
	Item* key;
};

