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
#include <cmath>
#include <queue>

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
    void draw()
    { // 透明大圆嵌套实心小圆
        sf::CircleShape circle(10.0);
        circle.setFillColor(sf::Color::Transparent);
        circle.setOutlineColor(color);
        circle.setOutlineThickness(2.0);
        circle.setPosition(position.x - 10.0, position.y - 10.0);
        window.draw(circle);
        circle.setRadius(5.0);
        circle.setFillColor(color);
        circle.setPosition(position.x - 5.0, position.y - 5.0);
        window.draw(circle);
    }
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
    void draw()
    { // 透明线段
        sf::Vertex line[] =
        {
            sf::Vertex((sf::Vector2f)p1->position, color),
            sf::Vertex((sf::Vector2f)p2->position, color)
        };
        window.draw(line, 2, sf::Lines);
    }
};
extern std::unordered_map<int, line*> lines;


#define protect_start {std::lock_guard<std::mutex> lock(dataMutex);
#define protect_end }
