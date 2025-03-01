#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::Vector2f position;
    sf::Angle dir;
    sf::CircleShape circle;
    float r = 30.f;
public:
    Player(float posX = 0, float posY = 0)
    {
        position = {posX, posY};
        dir = sf::radians(0.f);

        circle.setPosition({ position.x - r, position.y - r });
        circle.setRadius(r);
        circle.setFillColor(sf::Color::Green);
        circle.setPointCount(32);
    }
    void render(sf::RenderWindow* window);
    void move(sf::Vector2f delta);
    void lookAt(sf::Vector2i target);
};

#endif // PLAYER_H
