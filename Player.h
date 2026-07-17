#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:

	int speed = 1;
	sf::RectangleShape playerShape; // квадрат
	
public:
	Player() // конструктор с значениями квадрата
	{
		playerShape.setSize(sf::Vector2f(100, 50));
		playerShape.setFillColor(sf::Color::Black);
		playerShape.setPosition(sf::Vector2f{ 10, 20 });
	}

	void update();
	void Draw(sf::RenderWindow& window); // доступ к основному окну через функцию


};

