#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{
	sf::RenderWindow window;
	sf::Clock clock;
	float timer = 0.f;
	Player player;

private:
	void processEvents();

	void update(float deltaTime);

	void render();

public:
	Game() : window(sf::VideoMode({ 400, 400 }), L"RPG_Project", sf::Style::Default)
	{
		window.setVerticalSyncEnabled(true);

  	}
	
	
   void run();
};

