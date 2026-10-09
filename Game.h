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
	sf::View view;
	float zoomLevel = 1.f;

	//базовая высота камеры
	float baseViewHeight = 720.f;

private:
	void processEvents();

	void update(float deltaTime);

	void render();

public:
	Game() : window(sf::VideoMode(sf::VideoMode::getDesktopMode()), L"RPG_Project", sf::Style::Default)
	{
		window.setVerticalSyncEnabled(true);

		playerView.setSize({ 100, 100 });
		playerView.setColor(sf::Color::Black);

		view.setSize({ 1280, 720 });
 	}
		
   void run();


   void draw(sf::RenderWindow& window);
};

