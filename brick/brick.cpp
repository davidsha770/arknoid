#include "brick.hpp"

GreenBrick::GreenBrick(sf::Vector2f const& position, sf::Vector2f const& size)
{
    setSize(sf::Vector2f(size));
    setPosition(position);
    setFillColor(sf::Color::Green);
}

RedBrick::RedBrick(sf::Vector2f const& position, sf::Vector2f const& size)
{
    setSize(sf::Vector2f(size));
    setPosition(position);
    setFillColor(sf::Color::Red);
}

BlueBrick::BlueBrick(sf::Vector2f const& position, sf::Vector2f const& size)
{
    setSize(sf::Vector2f(size));
    setPosition(position);
    setFillColor(sf::Color::Blue);
}

yellowBrick::yellowBrick(sf::Vector2f const& position, sf::Vector2f const& size)
{
    setSize(sf::Vector2f(size));
    setPosition(position);
    setFillColor(sf::Color::Yellow);
}