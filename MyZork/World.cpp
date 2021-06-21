#include<iostream>
#include "World.h"
#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include "Player.h"

World::World() {

	// ROOMS
	Room* _entrance = new Room("Entrance", "You are in a dark room illuminated by a hole in the ceiling.");
	Room* _forge = new Room("Forge", "You are in an abandoned forge surrouned by broken tools.");
	Room* _darkRoom = new Room("DarkRoom", "You are in a small room.");
	Room* _habitatedRoom = new Room("HabitatedRoom", "You are in a room where has someone lived for a long time.");
	Room* _treasureChamber = new Room("TreasureChamber", "You are in a big room full of gold and treasures.");
	
	entities.push_back(_entrance);
	entities.push_back(_forge);
	entities.push_back(_darkRoom);
	entities.push_back(_habitatedRoom);
	entities.push_back(_treasureChamber);

	// EXITS
	Exit* _goldenDoor = new Exit("GoldenDoor", "You see a shiny golden door.", "east", "west", _entrance, _treasureChamber);
	Exit* _ironDoor = new Exit("IronDoor", "You see a iron door.", "north", "south", _entrance, _forge);
	Exit* _door = new Exit("Door", "You see a wooden door with no knob.", "south", "north", _darkRoom, _habitatedRoom);
	Exit* _hole = new Exit("HoleOnTheWall", "You see a small hole but a person could crawl past.", "west", "east", _entrance, _darkRoom);

	entities.push_back(_goldenDoor);
	entities.push_back(_ironDoor);
	entities.push_back(_door);
	entities.push_back(_hole);

	// PLAYER
	player = new Player(_entrance);
}

World::~World() {

}

bool World::Update(const vector<string>& _action) {
	switch (_action.size()) {
		case 1:

			break;

		case 2:
			if (_action[0] == "go") player->Move(_action[1]);
			return true;
			break;

		default:
			return false;
	}
	return false;
}