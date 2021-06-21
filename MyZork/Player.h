#include <string>
#include <list>

using namespace std;

class Room;
class Item;

#pragma once
class Player
{
public:
	Player(Room* _location);

	bool Move(const string& _direction);
	void Look();
	void Look(const string& _direction);
	void Examine();
	void Examine(const string& _entity);
	void Pick(const string& _item);
	void Inventory();
	void Drop(const string& _item);

private:
	Room* location;
	list<Item*> inventory;
};

