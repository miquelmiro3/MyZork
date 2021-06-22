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
	bool ValidDirection(string& _direction);
	bool Update(const vector<string>& _action);

	bool quit;

private:
	vector<Entity*> entities;
	Player* player;
};

