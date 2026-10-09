#include "Game.h"

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
    // Сброс направления, то есть каждый кадр начинается с того что игрок не двигается
    // а потом уже добавляется движение персонажа
    direction = { 0, 0 };

    // При нажатии кнопки персонаж перемещаеться в нужное направление
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        direction.x -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        direction.x += 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        direction.y -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        direction.y += 1.f;
    }

    player.move(direction, deltaTime);
}   

void Game::render()
{
    window.clear(sf::Color::White);

    draw(window); // поменял player на  world

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

void Game::draw(sf::RenderWindow& window)
{
    playerView.setPosition(player.getPosition());

    playerView.draw(window);
}

