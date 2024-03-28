#include <unistd.h>
#include "manager.hpp"
#include "screen.hpp"
#include "sub_man.hpp"

Manager::Manager()
: m_window{sf::VideoMode(1280, 680), "Arkanoid!"}
, m_screen_size{m_window.getSize()}
, m_ball{m_screen_size.x/2, m_screen_size.y - m_screen_size.y / 20, m_screen_size.y / 70}
, m_surfase{sf::Vector2f(m_screen_size.x / 10, m_screen_size.y / 80)
, sf::Vector2f(m_screen_size.x/2, m_screen_size.y - m_screen_size.y/70)}
, m_status{"level 1"}
, m_score{0}
{
}

void Manager::managment()
{
    std::shared_ptr<Screen> screen(std::make_shared<LevelScreen>());
    std::shared_ptr<SubMan> subman(std::make_shared<LevelMan>(3));
    unsigned int check;

    std::vector<std::pair<BrickType, sf::Vector2f>> brickInfo;

    for (size_t line = 0; line < 4; ++line) {
        BrickType brickType;
        if (line == 0) {
            brickType = BrickType::Green;
        } else if (line == 1) {
            brickType = BrickType::Red;
        } else if (line == 2) {
            brickType = BrickType::Blue;
        } else {
            brickType = BrickType::Yellow;
        }
        for (float i = 0; i < 5; ++i) {
            sf::Vector2f position(10.f + i * m_screen_size.x / 5, static_cast<float>(100 + line * 80));

            brickInfo.push_back(std::make_pair(brickType, position));
        }
    }
    maker(*this, brickInfo);

     while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            } else {
                subman.get()->check_event(*this);
            }
        }

        check = subman.get()->managment(*this);
        if (check == 1) {
            m_window.close();
        } else if (check == 2) {
            sleep(5);   
            subman = std::make_shared<LevelMan>(3);
            m_ball.init_ball(m_surfase.getGlobalBounds(), m_surfase.getSize().x);
            maker(*this, brickInfo);
        }
        
        m_window.clear();
        screen.get()->display(*this);
        m_window.display();
    }
}