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
struct CAMERA{double x, y, zoom;};
extern CAMERA camera;


#define protect_start {std::lock_guard<std::mutex> lock(dataMutex);
#define protect_end }
