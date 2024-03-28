#pragma once

#include <SFML/Graphics.hpp>
#include "brick.hpp"

class Ball : public sf::CircleShape
{
public:
    Ball(float x, float y, float rad);
    ~Ball() = default;
    void move_b();
    void change_valo(unsigned int direct);
    void move_right();
    void move_left();
    void init_ball(sf::FloatRect surfaseBounds, float surfase_x);

private:
    sf::Vector2f m_valo;
};