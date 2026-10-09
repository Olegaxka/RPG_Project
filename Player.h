#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.h"

class Player 
	: public Entity
{
private:
	
	float speed = 200.f;

public:
	Player() 
	{
		setPosition(10, 10);
	}

	// position += direction * speed * deltaTime ( Формула скорости )
	void move(sf::Vector2f direction, float deltaTime); 


};

