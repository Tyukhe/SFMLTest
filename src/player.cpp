#include "player.h"
#include <cmath>

void Player::render(sf::RenderWindow *window)
{
    window->draw(circle);
    sf::RectangleShape line({75.f, 2.f});
    line.setFillColor(sf::Color::Red);
    line.setPosition(position);
    line.rotate(dir);
    window->draw(line);
}

void Player::move(sf::Vector2f delta)
{
    if (delta.length() != 0)
    {
        delta = delta.normalized();
        delta = { delta.x * 8, delta.y * 8 };
    }
    delta = delta.rotatedBy(dir);
    position += delta;
    circle.setPosition({ position.x - r, position.y - r });
}

void Player::lookAt(sf::Vector2i target)
{
    float x = target.x - position.x, y = target.y - position.y;
    if (x >= 0 && y >= 0)
    {
        dir = sf::radians(std::atan(y / x));
    }else if (x <= 0 && y >= 0)
    {
        dir = sf::radians(-std::atan(x / y)) + sf::degrees(90);
    }else if (x >= 0 && y <= 0)
    {
        dir = sf::radians(-std::atan(x / y)) - sf::degrees(90);
    }else
    {
        dir = -sf::radians(std::atan(x / y)) - sf::degrees(90);
    }
}
