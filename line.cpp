#include "line.hpp"

void line::draw()
{
    sf::Vertex line[] = {
        sf::Vertex((sf::Vector2f)p1->position, color),
        sf::Vertex((sf::Vector2f)p2->position, color)
    };
    window.draw(line, 2, sf::Lines);
}
