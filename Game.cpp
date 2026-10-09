#include "Game.h"

void Game::processEvents() 
{

    while (auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }

        if (const auto* wheel = event->getIf<sf::Event::MouseWheelScrolled>())
        {
            if (wheel->delta > 0)
            {
                float newZoomLevel = zoomLevel * 0.9f;

                if (newZoomLevel >= 0.5f)
                {
                    zoomLevel = newZoomLevel;
                    view.zoom(0.9f);
                }
            }
            else if (wheel->delta < 0)
            {
                float newZoomLevel = zoomLevel * 1.1f;

                if (newZoomLevel <= 1.5f)
                {
                    zoomLevel = newZoomLevel;
                    view.zoom(1.1f);
                }
            }
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

    view.setCenter({ player.getPosition().x + 50, player.getPosition().y + 50 });
}   

void Game::render()
{
    window.clear(sf::Color::White);

    window.setView(view);

    draw(window);

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

    // Проверка работы камеры
    sf::RectangleShape marker;
    marker.setSize({ 50, 50 });
    marker.setFillColor(sf::Color::Red);
    marker.setPosition({ 300, 300 });
    window.draw(marker);
    /*
    marker.setPosition({ 300, 300 }); — задаёт постоянные координаты объекта в игровом мире.
    view.setCenter(player.getPosition()); — перемещает камеру вслед за игроком.
    window.setView(view); — заставляет окно отображать мир через эту камеру.
    window.draw(marker); — рисует ориентир с учётом положения камеры.*/

    playerView.draw(window);
}

