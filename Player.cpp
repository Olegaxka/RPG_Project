#include "Player.h"



// В Player мы рассчитываем, на сколько нужно сдвинуть объект,
// а в Entity уже выполняется само изменение позиции объекта.
void Player::move(sf::Vector2f direction, float deltaTime)
{
    if (direction.x != 0 || direction.y != 0)
    {
        sf::Vector2f normalizedDirection = direction.normalized();

        sf::Vector2f movement = normalizedDirection * speed * deltaTime;

        Entity::move(movement.x, movement.y);
    }
}

