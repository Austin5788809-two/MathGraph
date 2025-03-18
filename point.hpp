#pragma once
#include "config.h"
struct point
{
    std::string name;
    sf::Vector2d position;
    sf::Color color; // random color
    bool hovering = 0;
    void draw();
    void update();
};
extern std::unordered_map<std::string, point*> points;
