#include "Entity.h"
#include "Room.h"

class Exit : public Entity
{
public:
	DirectionType direction;
	Room* source;
	Room* destination;
};

