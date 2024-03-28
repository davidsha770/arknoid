#include "screen.hpp"
#include <iostream>
#include <string>

void StartScreen::display(Manager& man)
{
    man.m_window.clear(sf::Color::White);
    man.m_window.display();
}

void LevelScreen::display(Manager& man)
{

    sf::Font font;
    if (!font.loadFromFile("fonts/OpenSans-Bold.ttf")) {
        man.m_window.close();
        std::cout<<"font don't found\n";
    }
    sf::Text score("score: "+std::to_string(man.m_score), font);
    score.setCharacterSize(70);
    score.setFillColor(sf::Color::White);
    man.m_window.clear();
    man.m_window.draw(man.m_ball);
    man.m_window.draw(man.m_surfase);
    man.m_window.draw(score);
    auto it = man.m_bricks.begin();
    while (it != man.m_bricks.end()) {
        man.m_window.draw(**it);
        ++it;
    }
    man.m_window.display();
}

void GameoverScreen::display(Manager& man)
{
    man.m_window.clear();
    man.m_window.display();
}