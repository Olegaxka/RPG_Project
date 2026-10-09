#include "EntityView.h"

void EntityView::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void EntityView::setSize(sf::Vector2f size)
{

	shape.setSize(size);

}
void EntityView::setPosition(sf::Vector2f position)
{
	shape.setPosition(position);
}
void EntityView::setColor(sf::Color color)
{
	shape.setFillColor(color);
}