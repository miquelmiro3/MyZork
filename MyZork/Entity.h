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

enum DirectionType
{
	north,
	west,
	south,
	east
};


class Entity
{
public:
	EntityType type;
	string name;
	string description;
	list<Entity*> contains;
};

