#include <string>
#include <list>

using namespace std;

class Room;
class Item;

#pragma once
class Player
{
public:
	Player(int _health, int _attack, Room* _location);

	bool Move(const string& _direction);
	void Look();
	void Look(const string& _direction);
	void Examine();
	void Examine(const string& _entity);
	void Pick(const string& _item);
	void Inventory();
	void Drop(const string& _item);
	void Stats();
	bool Attack(const string& _objective);
	void Equip(const string& _equipable);
	void Combine(const string& _item1, const string& _item2);

	int health;
	int maxHealth;
	int attack;

private:
	Room* location;
	list<Item*> inventory;
	Item* equipped;
};

