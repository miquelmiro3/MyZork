#include "Entity.h"

class Room;
class Item;

#pragma once
class Creature : public Entity
{
public:
	Creature(const string& _name, const string& _description, int _health, int _attack, Room* _location);

	void Die();

	Room* location;
	Item* protecting;
	int health;
	int maxHealth;
	int attack;
};

