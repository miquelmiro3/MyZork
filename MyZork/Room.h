#include "Entity.h"

class Exit;
class Item;

#pragma once
class Room : public Entity
{
public:
	Room(const string& _name, const string& _description, Entity* _parent = NULL);

	Exit* FindExit(const string _direction);
	void Examine();
	bool Examine(const string& _entity);
	Item* FindItem(const string& _item);

	list<Exit*> exits;
};

