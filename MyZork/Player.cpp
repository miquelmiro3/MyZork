#include <iostream>
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"

Player::Player(Room* _location) {
	location = _location;
}

bool Player::Move(const string& _direction) {
	Exit* _exit = location->FindExit(_direction);

	if (_exit == NULL) cout << " You can't do that." << endl;
	else {
		if (_exit->locked) {
			for (list<Item*>::iterator _it = inventory.begin(); _it != inventory.end(); _it++) {
				if (_exit->key == (*_it)) {
					cout << "  You have opened the door with the: " << (*_it)->name << endl;
					_exit->locked = false;
				}
			}
			if (_exit->locked) {
				cout << " The door is closed." << endl;
				return false;
			}
		}
		Room* _newRoom = (location == _exit->source) ? _exit->destination : _exit->source;
		cout << " " << _newRoom->name << endl;
		cout << " " << _newRoom->description << endl;
		location = _newRoom;

		if (location->name == "TreasureChamber") {
			cout << " YOU WIN! YOU FOUND THE LOST TREASURE!" << endl;
			return true;
		}
		return false;
	}
}

void Player::Look() {
	cout << " " << location->name << endl;
	cout << " " << location->description << endl;
}

void Player::Look(const string& _direction) {
	Exit* _exit = location->FindExit(_direction);

	if (_exit == NULL) cout << " There is no door there." << endl;
	else cout << " " << _exit->description << endl;
}

void Player::Examine() {
	location->Examine();
}

void Player::Examine(const string& _entity) {
	bool found = location->Examine(_entity);
	if (found) return;
	
	for (list<Item*>::iterator _it = inventory.begin(); _it != inventory.end(); _it++) {
		if ((*_it)->name == _entity) {
			cout << " " << (*_it)->description << endl;
			return;
		}
	}
	cout << " You can't see that." << endl;
}

void Player::Pick(const string& _item) {
	Item* _pickedItem = location->FindItem(_item);

	if (_pickedItem == NULL) cout << " You can't pick that." << endl;
	else {
		if (_pickedItem->locked) cout << " You can't pick that because is protected by: " << _pickedItem->GetProtectorName() << endl;
		else {
			cout << " You picked: " << _pickedItem->name << endl;
			location->contains.remove(_pickedItem);
			inventory.push_back(_pickedItem);
		}
	}
}

void Player::Inventory() {
	if (inventory.size() <= 0) {
		cout << " You don't have anything in the inventory." << endl;
		return;
	}
	
	cout << " You have a:" << endl;
	for (list<Item*>::iterator _it = inventory.begin(); _it != inventory.end(); _it++) {
		cout << "  " << (*_it)->name << endl;
	}
}

void Player::Drop(const string& _item) {

	for (list<Item*>::iterator _it = inventory.begin(); _it != inventory.end(); _it++) {
		if ((*_it)->name == _item) {
			cout << " " << "You dropped: " << (*_it)->name << endl;
			location->contains.push_back((*_it));
			inventory.remove((*_it));
			return;
		}
	}
	cout << " You can't drop that." << endl;
}