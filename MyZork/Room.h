#include "Entity.h"

class Exit;

#pragma once
class Room : public Entity
{
public:
	Room(const string& _name, const string& _description, Entity* _parent = NULL);

	Exit* FindExit(const string _direction);

	list<Exit*> exits;
};

