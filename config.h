#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <optional>

namespace sf{
typedef sf::Vector2<double> Vector2d;
}
extern sf::RenderWindow window;
extern int windowWidth;
extern int windowHeight;
struct point
{
    static int id_cnt;
    int id;
    sf::Vector2d position;
    sf::Color color; // random color
    point() : id(id_cnt++) {}
};
extern int point::id_cnt = 0;
std::unordered_map<int, point*> points;
struct line
{
    static int id_cnt;
    int id;
    int id_p1, id_p2;
    sf::Color color; // random color
    line() : id(id_cnt++) {}
};
extern int line::id_cnt = 0;
std::unordered_map<int, line*> lines;
