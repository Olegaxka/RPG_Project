#include "Game.h"
#include <iostream>



void Game::processEvents() 
{

    while (auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
    }
}

void Game::update(float deltaTime)
{
    timer += deltaTime;
}   

void Game::render()
{
    window.clear(sf::Color::White);

    player.Draw(window);

    window.display();
}

void Game::run()
{
    while (window.isOpen())
    {
        sf::Time timeRestart = clock.restart();
        float deltaTime = timeRestart.asSeconds();

        processEvents();

        update(deltaTime);

        render();
    }
}
