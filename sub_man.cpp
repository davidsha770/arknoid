#include "sub_man.hpp"
#include <vector>
#include <iostream>

LevelMan::LevelMan(unsigned int life)
: m_started{false}
, m_life{life}
{
}

unsigned int LevelMan::managment(Manager& man)
{
    if (m_started) {
        man.m_ball.move_b();
    }
    if (check_collision(man)) {
        return 1;
    } if (man.m_bricks.empty()) {
        return 2;
    } return 0;
}

void LevelMan::check_event(Manager& man)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (man.m_surfase.move_right(man.m_screen_size.x)) {
            if (!m_started) {
                man.m_ball.move_right();
            }
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (man.m_surfase.move_left()) {
            if (!m_started) {
                man.m_ball.move_left();
            }
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        m_started = true;
    }
}

static unsigned int direct_collision(float dx, float dy)
{
    if (std::abs(dx) > std::abs(dy)) {
        return 1;
    }
    return 2;
}

bool LevelMan::check_collision(Manager& man)
{
    sf::FloatRect ballBounds = man.m_ball.getGlobalBounds();
    unsigned int direct = 0; 
    auto it = man.m_bricks.begin();
    while (it != man.m_bricks.end()) {
        sf::FloatRect brickBounds = it->get()->getGlobalBounds();
        if (ballBounds.intersects(brickBounds)) {
            float dx{ballBounds.left - brickBounds.left};
            float dy{ballBounds.top - brickBounds.top};
            direct = direct_collision(dx, dy);
            it = man.m_bricks.erase(it);
            man.m_score += 40;
        } else {
            ++it;
        }
    }
    
    sf::FloatRect surfaseBounds = man.m_surfase.getGlobalBounds();
    if (ballBounds.intersects(surfaseBounds)) {
        direct = 2;
    }

    if (ballBounds.left < 0) {
        direct = 1;
    } else if (ballBounds.left + ballBounds.width > man.m_screen_size.x) {
        direct = 1;
    } else if (ballBounds.top < 0) {
        direct = 2;
    } else if (ballBounds.top + ballBounds.height > man.m_screen_size.y) {
        m_life--;
        if (m_life != 0) {
            m_started = false;
            direct = 0;
            man.m_ball.init_ball(surfaseBounds, man.m_surfase.getSize().x);
        } else {
            return true;
        }
    }

    if (direct != 0) {
        man.m_ball.change_valo(direct);
    }
    return false;
}

void maker(Manager& man, std::vector<std::pair<BrickType, sf::Vector2f>> const& bricks)
{
    for (const auto& pair : bricks) {
        const BrickType brickType = pair.first;
        const sf::Vector2f& position = pair.second;
        switch (brickType)
        {
            case BrickType::Green:
                man.m_bricks.push_back(std::make_shared<GreenBrick>(position, sf::Vector2f(man.m_screen_size.x / 6, man.m_screen_size.y / 10)));
                break;

            case BrickType::Red:
                man.m_bricks.push_back(std::make_shared<RedBrick>(position, sf::Vector2f(man.m_screen_size.x / 6, man.m_screen_size.y / 10)));
                break;

            case BrickType::Blue:
                man.m_bricks.push_back(std::make_shared<BlueBrick>(position, sf::Vector2f(man.m_screen_size.x / 6, man.m_screen_size.y / 10)));
                break;

            case BrickType::Yellow:
                man.m_bricks.push_back(std::make_shared<yellowBrick>(position, sf::Vector2f(man.m_screen_size.x / 6, man.m_screen_size.y / 10)));
                break;

            default:
                // Handle unknown brick type
                break;
        }
    }
}