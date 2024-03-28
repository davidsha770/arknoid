#include "surface.hpp"

Surfase::Surfase(sf::Vector2f size, sf::Vector2f position)
{
    setSize(sf::Vector2f(size));
    setFillColor(sf::Color::Green);
    setPosition(sf::Vector2f(position.x - size.x/2, position.y - size.y/2));
}

bool Surfase::move_right(float width)
{
    if (getPosition().x < width - getSize().x) {
        move(15.f, 0.f);
        return true;
    }
    return false;
}

bool Surfase::move_left()
{
    if (getPosition().x > 0){
        move(-15.f, 0.f);
        return true;
    }
    return false;
}