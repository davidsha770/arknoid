#pragma once
#include <SFML/Graphics.hpp>
#include "manager.hpp"

class Screen
{
public:
    virtual ~Screen() = default;
    virtual void display(Manager& man) = 0;

protected:
    Screen() = default;
    Screen(const Screen&) = default;
    Screen& operator=(const Screen&) = default;
};

class StartScreen : public Screen
{
public:
    void display(Manager& man);
};

class LevelScreen : public Screen
{
public:
    void display(Manager& man);
};

class GameoverScreen : public Screen
{
public:
    void display(Manager& man);
};
