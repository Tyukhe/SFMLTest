#include "button.h"
#include <SFML/Graphics.hpp>

void Button::setText(sf::String newText, sf::Font newFont)
{
    text = newText;
    font = newFont;
}

void Button::render(sf::RenderWindow* window)
{
    window->draw(rectangle);
    sf::Text title(font);
        title.setString(text);
        title.setCharacterSize(w - 4);
        title.setFillColor(sf::Color::Black);
        title.setPosition({ x + 7, y });
        window->draw(title);

}

bool Button::clicked(sf::Vector2i position)
{
    if (position.x > x && position.x < (x + h) && position.y > y && position.y < (y + w)){
        return true;
    }
    return false;
}
