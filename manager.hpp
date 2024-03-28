#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>
#include "ball.hpp"
#include "surface.hpp"
#include "brick.hpp"

class Manager
{
public:
    Manager();
    ~Manager() = default;
    void managment();

// protected:
    sf::RenderWindow m_window;
    sf::Vector2f m_screen_size;
    Ball m_ball;
    Surfase m_surfase;
    std::vector<std::shared_ptr<AbcBrick>> m_bricks;
    std::string m_status;
    unsigned int m_score;
};
