#include<iostream>
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
	Creature* _orc = new Creature("Orc", "A soldier orc, you may win him with a good weapon.", _habitatedRoom);

	// ITEMS
	Item* _sword = new Item("Sword", "A standard sword.", _entrance);
	Item* _magicRune = new Item("MagicRune", "A magic rune that can be attached to a sword.", _forge);
	Item* _ironKey = new Item("IronKey", "A iron key.", _darkRoom);
	Item* _goldenKey = new Item("GoldenKey", "A golden key.", _habitatedRoom);

	_goldenKey->Lock(_orc);

	// EXITS
	Exit* _goldenDoor = new Exit("GoldenDoor", "You see a shiny golden door.", "east", "west", _entrance, _treasureChamber);
	Exit* _ironDoor = new Exit("IronDoor", "You see a iron door.", "north", "south", _entrance, _forge);
	Exit* _door = new Exit("Door", "You see a wooden door with no knob.", "south", "north", _darkRoom, _habitatedRoom);
	Exit* _hole = new Exit("HoleOnTheWall", "You see a small hole but a person could crawl past.", "west", "east", _entrance, _darkRoom);

	_goldenDoor->Lock(_goldenKey);
	_ironDoor->Lock(_ironKey);

	// PLAYER
	player = new Player(_entrance);
}

World::~World() {

}

bool World::Update(const vector<string>& _action) {
	switch (_action.size()) {
		case 1:
			if (_action[0] == "look" || _action[0] == "l") {
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
			break;

		case 2:
			if (_action[0] == "look" || _action[0] == "l") {
				player->Look(_action[1]);
				return true;
			}
			else if (_action[0] == "examine" || _action[0] == "e") {
				player->Examine(_action[1]);
				return true;
			}
			else if (_action[0] == "move" || _action[0] == "m") {
				quit = player->Move(_action[1]);
				return true;
			}
			else if (_action[0] == "pick" || _action[0] == "p") {
				player->Pick(_action[1]);
				return true;
			}
			else if (_action[0] == "drop" || _action[0] == "d") {
				player->Drop(_action[1]);
				return true;
			}
			break;

		case 3:
			break;

		default:
			return false;
	}
	return false;
}


//----move direction
//----look a solas -> habitacion
//----look direction -> portas
//----examine a solas -> cosas de la habitacion
//----examine x -> item / creature de la room i inventory
//----inventory
//----pick x
//----drop x
//----quit
//attack x
//equip x
//combine x y
//stats
//help