#include <iostream>
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Creature.h"

Player::Player(int _health, int _attack, Room* _location) {
	health = _health;
	maxHealth = _health;
	attack = _attack;
	location = _location;
	equipped = NULL;
}

bool Player::Move(const string& _direction) {
	Exit* _exit = location->FindExit(_direction);

	if (_exit == NULL) {
		cout << " You can't do that." << endl;
		return false;
	}
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
			if ((*_it)->contains.size() > 0) {
				cout << " It contains: " << endl;
				for (list<Entity*>::iterator _it2 = (*_it)->contains.begin(); _it2 != (*_it)->contains.end(); _it2++) {
					cout << "  " << (*_it2)->name << endl;
				}
			}
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
			if ((*_it) == equipped) {
				cout << " You can't drop an equipped item." << endl;
				return;
			}
			cout << " You dropped: " << (*_it)->name << endl;
			location->contains.push_back((*_it));
			inventory.remove((*_it));
			return;
		}
	}
	cout << " You can't drop that." << endl;
}

void Player::Stats() {
	cout << " You have:" << endl;
	cout << "  Health: " << health << "/" << maxHealth << endl;
	cout << "  Attack: " << attack << endl;
}

bool Player::Attack(const string& _objective) {
	Creature* _c = location->FindCreature(_objective);
	_c->health -= attack;
	if (_c->health <= 0) {
		cout << " You have won the: " << _c->name << endl;
		_c->Die();
	}
	else {
		health -= _c->attack;

		cout << " You have dealt: " << attack << " of dmg" << endl;
		cout << " You have received: " << _c->attack << " of dmg" << endl;

		if (health <= 0) {
			cout << " You died. Game over." << endl;
			return true;
		}
	}
	return false;
}

void Player::Equip(const string& _equipable) {
	for (list<Item*>::iterator _it = inventory.begin(); _it != inventory.end(); _it++) {
		if ((*_it)->name == _equipable) {
			if ((*_it)->itemType != equipable) cout << " You can't equip that." << endl;
			else {
				equipped = (*_it);
				attack += (*_it)->attack;
				cout << " You have equipped: " << (*_it)->name << endl;
			}
			return;
		}
	}
	cout << " You don't have that item in your inventory." << endl;
}

void Player::Combine(const string& _item1, const string& _item2) {
	Item* _equipable = NULL;
	Item* _upgrade = NULL;
	for (list<Item*>::iterator _it = inventory.begin(); _it != inventory.end(); _it++) {
		if ((*_it)->name == _item1 || (*_it)->name == _item2) {
			if ((*_it)->itemType == equipable) {
				if (_equipable == NULL) _equipable = (*_it);
				else {
					cout << " You can't combine 2 equipable items." << endl;
					return;
				}
			}
			else if ((*_it)->itemType == upgrade) {
				if (_upgrade == NULL) _upgrade = (*_it);
				else {
					cout << " You can't combine 2 upgrade items." << endl;
					return;
				}
			}
			else {
				cout << " You can't combine this item: " << (*_it)->name << endl;
				return;
			}
		}
	}
	if (_equipable == NULL || _upgrade == NULL) cout << " You don't have this items." << endl;
	else {
		cout << " You combined the items." << endl;
		_equipable->contains.push_back(_upgrade);
		inventory.remove(_upgrade);
		if (_equipable == equipped) attack += _upgrade->attack;
		_equipable->attack += _upgrade->attack;

	}
}
