#include "point.hpp"

void point::draw()
{ 
    sf::CircleShape outerCircle;
    sf::CircleShape innerCircle;

    // 根据 camera.zoom 调整点的大小
    double baseRadius = 10.0; // 基础半径
    double radius = baseRadius / (1.0 + camera.zoom * 0.1); // 缩放公式
    if (radius < 1.0) radius = 1.0; // 设置最小半径

    // 计算相对于摄像头的绘制位置
    sf::Vector2f adjustedPosition;
    adjustedPosition.x = (position.x - camera.x) * (1.0 + camera.zoom) + windowWidth / 2.0;
    adjustedPosition.y = (position.y - camera.y) * (1.0 + camera.zoom) + windowHeight / 2.0;

    // 外圈（透明大圆）
    outerCircle.setRadius(radius * (1.5 + (hovering ? 0.5 : 0)));
    outerCircle.setFillColor(sf::Color(color.r, color.g, color.b, 50)); // 半透明
    outerCircle.setOrigin(outerCircle.getRadius(), outerCircle.getRadius());
    outerCircle.setPosition(adjustedPosition);

    // 内圈（实心小圆）
    innerCircle.setRadius(radius);
    innerCircle.setFillColor(color);
    innerCircle.setOrigin(innerCircle.getRadius(), innerCircle.getRadius());
    innerCircle.setPosition(adjustedPosition);

    // 绘制到窗口
    window.draw(outerCircle);
    window.draw(innerCircle);
}

void point::update()
{
    // 获取鼠标在窗口中的位置
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    // 将鼠标位置转换为相对于摄像头的世界坐标
    sf::Vector2f worldMousePosition;
    worldMousePosition.x = (mousePosition.x - windowWidth / 2.0) / (1.0 + camera.zoom) + camera.x;
    worldMousePosition.y = (mousePosition.y - windowHeight / 2.0) / (1.0 + camera.zoom) + camera.y;

    // 计算鼠标与点的距离
    double distance = std::sqrt(std::pow(worldMousePosition.x - position.x, 2) + 
                                std::pow(worldMousePosition.y - position.y, 2));

    // 根据距离判断是否悬停
    double baseRadius = 10.0; // 基础半径
    double radius = baseRadius / (1.0 + camera.zoom * 0.1); // 缩放公式
    hovering = (distance <= radius) ? 1 : 0;
}