#include <string>
#include <list>

using namespace std;

#pragma once
enum EntityType
{
	roomExit,
	room,
	item,
	player,
	npc
};

class Entity
{
public:
	Entity(const string& _name, const string& _description, Entity* _parent = NULL);

	list<Entity*> FindEntity(EntityType _type);

	EntityType type;
	string name;
	string description;
	Entity* parent;
	list<Entity*> contains;
};

