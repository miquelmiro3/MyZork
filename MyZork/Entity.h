#include <string>
#include <list>

using namespace std;

#pragma once
enum EntityType
{
	roomExit,
	room,
	item,
	creature
};

class Entity
{
public:
	Entity(const string& _name, const string& _description, Entity* _parent = NULL);

	EntityType type;
	string name;
	string description;
	Entity* parent;
	list<Entity*> contains;
};

