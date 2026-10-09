#pragma once
#include <SFML/Graphics.hpp>

class EntityView
{
private:
    sf::RectangleShape shape;

public:
    void draw(sf::RenderWindow& window);

    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f position);
    void setColor(sf::Color color);
};
