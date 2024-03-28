#pragma once

#include <SFML/Graphics.hpp>

enum BrickType {
    Green,
    Red,
    Blue,
    Yellow,
};

class AbcBrick : public sf::RectangleShape
{
public:
    virtual ~AbcBrick() = default;

protected:
    AbcBrick() = default;
    AbcBrick(const AbcBrick&) = default;
    AbcBrick& operator=(const AbcBrick&) = default;
};

class GreenBrick : public AbcBrick
{
public:
    GreenBrick(sf::Vector2f const& position, sf::Vector2f const& size);
};

class RedBrick : public AbcBrick
{
public:
    RedBrick(sf::Vector2f const& position, sf::Vector2f const& size);
};

class BlueBrick : public AbcBrick
{
public:
    BlueBrick(sf::Vector2f const& position, sf::Vector2f const& size);
};

class yellowBrick : public AbcBrick
{
public:
    yellowBrick(sf::Vector2f const& position, sf::Vector2f const& size);
};

// typedef std::pair<BrickType, sf::Vector2f> BrickPair