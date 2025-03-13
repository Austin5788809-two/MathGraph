#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <optional>
#include <thread>
#include <mutex>
#include <sstream>

namespace sf{
typedef sf::Vector2<double> Vector2d;
}
extern sf::RenderWindow window;
extern unsigned int windowWidth;
extern unsigned int windowHeight;
struct point
{
    std::string name;
    sf::Vector2d position;
    sf::Color color; // random color
};
extern std::unordered_map<std::string, point*> points;
struct line
{
    static int id_cnt;
    int id;
    point* p1;
    point* p2;
    sf::Color color; // random color
    line() : id(id_cnt++) {}
};
extern std::unordered_map<int, line*> lines;
