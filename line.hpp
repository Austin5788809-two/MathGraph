#pragma once
#include "config.h"
#include "point.hpp"
struct line
{
    static int id_cnt;
    int id;
    point* p1;
    point* p2;
    sf::Color color; // random color
    line() : id(id_cnt++) {}
    void draw();    
};
extern std::unordered_map<int, line*> lines;