#include <SFML/Graphics.hpp>
#include "button.h"
#include "player.h"

void game(){
    sf::RenderWindow* window= new sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }), "Game");

    window->setVerticalSyncEnabled(true);

    Player player(100, 100);
    sf::Vector2f vector = { 0, 0 };

    while (window->isOpen()) {
        while (const std::optional event = window->pollEvent()) {
            if (event->is<sf:: Event::Closed>()) {
                window->close();
            } else if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
                window->setView(sf::View(visibleArea));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                vector += sf::Vector2f{ 1, 0 };
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                vector += sf::Vector2f{ -1, 0 };
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                vector += sf::Vector2f{ 0, 1 };
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                vector += sf::Vector2f{ 0, -1 };
            }
        }
        window->clear(sf::Color::Black);

        player.lookAt(sf::Mouse::getPosition());
        player.move(vector);
        vector = { 0, 0 };
        player.render(window);

        window->display();
    }
    window->close();
    delete window;
}

int main() {
    sf::RenderWindow* window= new sf::RenderWindow(sf::VideoMode({ 640u, 360u }), "Menu", sf::Style::Close);

    window->setFramerateLimit(144);

    sf::Font font("font.ttf");
    sf::Text title(font);
    title.setString(L"BIG GAME");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::Green);

    sf::Text name(font);
    name.setString(L"Проверка шрифтов. v0.0.0");
    name.setCharacterSize(20);
    name.setPosition({ 5, 335});
    name.setFillColor(sf::Color::Green);

    Button play(100.f, 100.f, 100.f, 20.f);
    play.setText(L"Играть", font);
    Button exit(100.f, 130.f, 100.f, 20.f);
    exit.setText(L"Выход", font);

    sf::Vector2i position = { 0, 0 };

    short count = 2;

    while (window->isOpen()) {
        while (const std::optional event = window->pollEvent()) {
            if (event->is<sf:: Event::Closed>()) {
                window->close();
                delete window;
                return 0;
            } else if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
                window->setView(sf::View(visibleArea));
            } else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                position = sf::Mouse::getPosition();
                if (play.clicked(position))
                {
                    window->close();
                } else if (exit.clicked(position))
                {
                    if (count == 0)
                    {
                        window->close();
                        delete window;
                        return 0;
                    } else
                    {
                        count--;
                    }
                }
            }
        }
        window->clear(sf::Color::Black);

        play.render(window);
        exit.render(window);
        window->draw(title);
        window->draw(name);

        window->display();
    }
    window->close();
    delete window;
    game();
    return 0;
}
