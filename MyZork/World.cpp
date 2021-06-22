#include <iostream>
#include "World.h"
#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Player.h"
#include "Creature.h"

World::World() {
	quit = false;

	// ROOMS
	Room* _entrance = new Room("Entrance", "You are in a dark room illuminated by the hole in the ceiling from where you have fallen.");
	Room* _forge = new Room("Forge", "You are in an abandoned forge surrouned by broken tools.");
	Room* _darkRoom = new Room("DarkRoom", "You are in a small room.");
	Room* _habitatedRoom = new Room("HabitatedRoom", "You are in a room where someone has lived for a long time.");
	Room* _treasureChamber = new Room("TreasureChamber", "You are in a big room full of gold and treasures.");
	
	entities.push_back(_entrance);
	entities.push_back(_forge);
	entities.push_back(_darkRoom);
	entities.push_back(_habitatedRoom);
	entities.push_back(_treasureChamber);

	// CREATURES
	Creature* _orc = new Creature("Orc", "A soldier orc, you may win him with a good weapon.", 20, 8, _habitatedRoom);

	// ITEMS
	Item* _sword = new Item("Sword", "A standard sword.", equipable, _entrance);
	Item* _magicRune = new Item("MagicRune", "A magic rune that can be attached to a sword.", upgrade, _forge);
	Item* _ironKey = new Item("IronKey", "A iron key.", key, _darkRoom);
	Item* _goldenKey = new Item("GoldenKey", "A golden key.", key, _habitatedRoom);

	_goldenKey->Lock(_orc);
	_sword->attack = 4;
	_magicRune->attack = 4;

	// EXITS
	Exit* _goldenDoor = new Exit("GoldenDoor", "You see a shiny golden door.", "east", "west", _entrance, _treasureChamber);
	Exit* _ironDoor = new Exit("IronDoor", "You see a iron door.", "north", "south", _entrance, _forge);
	Exit* _door = new Exit("Door", "You see a wooden door with no knob.", "south", "north", _darkRoom, _habitatedRoom);
	Exit* _hole = new Exit("HoleOnTheWall", "You see a small hole but a person could crawl past.", "west", "east", _entrance, _darkRoom);

	_goldenDoor->Lock(_goldenKey);
	_ironDoor->Lock(_ironKey);

	// PLAYER
	player = new Player(20, 2, _entrance);
}

World::~World() {

}


bool World::ValidDirection(string& _direction) {
	if (_direction == "north" || _direction == "west" || _direction == "south" || _direction == "east") return true;
	if (_direction == "n") {
		_direction = "north";
		return true;
	}
	if (_direction == "w") {
		_direction = "west";
		return true;
	}
	if (_direction == "s") {
		_direction = "south";
		return true;
	}
	if (_direction == "e") {
		_direction = "east";
		return true;
	}
	return false;
}

bool World::Update(const vector<string>& _action) {
	switch (_action.size()) {
		case 1:
			if (_action[0] == "help" || _action[0] == "h") {
				cout << " Possible directions:" << endl;
				cout << "  north (n), west (w), south (s), east (e)" << endl;
				cout << " Possible commands:" << endl;
				cout << "  (q) quit -> to exit the game" << endl;
				cout << "  (l) look -> to look the room" << endl;
				cout << "  (l) look direction -> to look at a direction of the room" << endl;
				cout << "  (m) move direction -> to move from a room to another" << endl;
				cout << "  (e) examine -> to examine the room for entities" << endl;
				cout << "  (e) examine entity -> to examine a item or a creature of the room or inventory (ex.: e Orc)" << endl;
				cout << "  (i) inventory -> to see the items of your inventory" << endl;
				cout << "  (p) pick item -> to pick an item of a room (ex.: p Sword)" << endl;
				cout << "  (d) drop item -> to drop an item to a room" << endl;
				cout << "  (s) stats -> to see the stats of your hero" << endl;
				cout << "  (eq) equip item -> to equip an item of the inventory" << endl;
				cout << "  (a) attack creature -> to attack a creature of a room" << endl;
				cout << "  (c) combine item1 item2 -> to combine items of the inventory (you only can combine equipables with upgrades)" << endl;
				return true;
			}
			else if (_action[0] == "look" || _action[0] == "l") {
				player->Look();
				return true;
			}
			else if (_action[0] == "examine" || _action[0] == "e") {
				player->Examine();
				return true;
			}
			else if (_action[0] == "inventory" || _action[0] == "i") {
				player->Inventory();
				return true;
			}
			else if (_action[0] == "quit" || _action[0] == "q") {
				quit = true;
				return true;
			}
			else if (_action[0] == "stats" || _action[0] == "s") {
				player->Stats();
				return true;
			}
			break;

		case 2:
			if (_action[0] == "look" || _action[0] == "l") {
				string _dir = _action[1];
				if (ValidDirection(_dir)) {
					player->Look(_dir);
					return true;
				}
				return false;
			}
			else if (_action[0] == "examine" || _action[0] == "e") {
				player->Examine(_action[1]);
				return true;
			}
			else if (_action[0] == "move" || _action[0] == "m") {
				string _dir = _action[1];
				if (ValidDirection(_dir)) {
					quit = player->Move(_dir);
					return true;
				}
				return false;
			}
			else if (_action[0] == "pick" || _action[0] == "p") {
				player->Pick(_action[1]);
				return true;
			}
			else if (_action[0] == "drop" || _action[0] == "d") {
				player->Drop(_action[1]);
				return true;
			}
			else if (_action[0] == "attack" || _action[0] == "a") {
				quit = player->Attack(_action[1]);
				return true;
			}
			else if (_action[0] == "equip" || _action[0] == "eq") {
				player->Equip(_action[1]);
				return true;
			}
			break;

		case 3:
			if (_action[0] == "combine" || _action[0] == "c") {
				player->Combine(_action[1], _action[2]);
				return true;
			}
			break;

		default:
			return false;
	}
	return false;
}