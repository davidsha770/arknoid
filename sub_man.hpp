#pragma once
#include <SFML/Graphics.hpp>
#include "manager.hpp"

class SubMan
{
public:
    virtual ~SubMan() = default;
    virtual unsigned int managment(Manager& man) = 0;
    virtual void check_event(Manager& man) = 0;

protected:
    SubMan() = default;
    SubMan(const SubMan&) = default;
    SubMan& operator=(const SubMan&) = default;
};

class StartMan : public SubMan
{
public:
    unsigned int managment(Manager& man);
    void check_event(Manager& man);
};

class LevelMan : public SubMan
{
public:
    LevelMan(unsigned int life);
    unsigned int managment(Manager& man);
    void check_event(Manager& man);

private:
    bool check_collision(Manager& man);

private:
    bool m_started{false};
    unsigned int m_life{3};
};

class GameoverMan : public SubMan
{
public:
    unsigned int managment(Manager& man);
    void check_event(Manager& man);
};

void maker(Manager& man, std::vector<std::pair<BrickType, sf::Vector2f>> const& bricks);