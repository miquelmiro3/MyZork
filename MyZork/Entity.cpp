#include "Entity.h"

Entity::Entity(const string& _name, const string& _description, Entity* _parent) {
	name = _name;
	description = _description;
	parent = _parent;

	if (parent != NULL) parent->contains.push_back(this);
}