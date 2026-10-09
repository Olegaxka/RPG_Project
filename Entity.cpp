#include "Entity.h"

sf::Vector2f Entity::getPosition() const
{
	return  position; 
}

void Entity::setPosition(float x, float y)
{
	position.x = x; 
	position.y = y;
}

void Entity::move(float x, float y)
{
	position.x += x;
	position.y += y;
}
