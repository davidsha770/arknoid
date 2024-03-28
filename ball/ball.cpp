#include "ball.hpp"
#include <cmath>
#include <random>

Ball::Ball(float x, float y, float rad)
{
    setRadius(rad);
    setFillColor(sf::Color::Red);
    setPosition(x - rad/2, y);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> angleDistribution(45.0f, 135.0f);

    float angle = angleDistribution(gen);
    float radians = angle * (3.14159265358979323846f / 180.0f);

    m_valo = sf::Vector2f(std::cos(radians), std::sin(radians));
}

void Ball::move_b()
{
    move(m_valo);
}

void Ball::move_right()
{
    move(15.f, 0.f);
}

void Ball::move_left()
{
    move(-15.f, 0.f);
}

void Ball::init_ball(sf::FloatRect surfaseBounds, float surfase_x)
{
    setPosition(sf::Vector2f(surfaseBounds.left + (surfase_x)/2 - getRadius(), surfaseBounds.top - (getRadius()*2)));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> angleDistribution(60.0f, 120.0f);

    float angle = angleDistribution(gen);
    float radians = angle * (3.14159265358979323846f / 180.0f);

    m_valo = sf::Vector2f(std::cos(radians), std::sin(radians));
}

void Ball::change_valo(unsigned int direct)
{
    if (direct == 1) {
        m_valo.x *= -1;
    } else {
        m_valo.y *= -1;
    }
}