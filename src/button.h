#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button
{
private:
    float x, y, h, w;
    sf::String text;
    sf::Font font;
    sf::RectangleShape rectangle;
public:
    Button(float posX, float posY, float height, float width)
    {
        x = posX;
        y = posY;
        h = height;
        w = width;
        rectangle.setSize({height, width});
        rectangle.setFillColor(sf::Color::Green);
        rectangle.setPosition({posX, posY});
    }
    void setText(sf::String newText, sf::Font font);
    void render(sf::RenderWindow* window);
    bool clicked(sf::Vector2i position);
};

#endif // BUTTON_H
