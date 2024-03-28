#pragma once

#include <SFML/Graphics.hpp>

class Surfase : public sf::RectangleShape
{
public:
    Surfase(sf::Vector2f size, sf::Vector2f position);
    ~Surfase() = default;
    bool move_right(float width);
    bool move_left();
};