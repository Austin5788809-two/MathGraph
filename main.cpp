#include "config.h"

sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}), "SFML works!");
int windowWidth = 800;
int windowHeight = 600;
int point::id_cnt = 0;
int line::id_cnt = 0;

int main()
{
    while (window.isOpen())
    {
        while (std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();
        window.display();
    }
    return 0;
}
