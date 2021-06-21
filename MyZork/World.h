#include <string>
#include <vector>
#include "Entity.h"
#include "Player.h"

using namespace std;

class World
{
public:
	World();
	~World();
	bool Update(const vector<string>& _action);

private:
	vector<Entity*> entities;
	Player* player;
};

