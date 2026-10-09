#pragma once
#include <SFML/Graphics.hpp>

class Entity
{

private:
	sf::Vector2f position;

public:
	
	virtual ~Entity() = default;

	sf::Vector2f getPosition() const;

	void setPosition(float x, float y);

	void move(float x, float y);
};







//void update();
//void draw(sf::RenderWindow& window);
//// возвращает текущую абсолютную позицию объекта в виде объекта
//sf::Vector2f getPosition() const;		
//// Устанавливает абсолютную позицию объекта.
//void setPosition(float xf, float yf);		
//// перемещает объект относительно его текущей позиции.
//void move(float xf, float yf);			
//// размер
//void setSize(sf::Vector2f size);	