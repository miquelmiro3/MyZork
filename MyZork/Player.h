#include <string>

using namespace std;

class Room;

#pragma once
class Player
{
public:
	Player(Room* _location);

	void Move(const string& _direction);

private:
	Room* location;
};

