#pragma once
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "World.h"

class Game
{
	sf::RenderWindow window;
	sf::Clock clock;
	World world;
	sf::Vector2f direction;
	EntityView playerView;
	Player player;

private:
	void processEvents();

	void update(float deltaTime);

	void render();

public:

	Game() : window(sf::VideoMode({ 400, 400 }), L"RPG_Project", sf::Style::Default)
	{
		window.setVerticalSyncEnabled(true);

		playerView.setSize({ 100, 50 });
		playerView.setColor(sf::Color::Black);
 	}
		
   void run();


   void draw(sf::RenderWindow& window);
};

