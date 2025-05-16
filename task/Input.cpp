#include "Engine.h"

void Engine::input()
{
    // Обработка Escape (теперь sf::Keyboard::Key::Escape)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        m_Window.close();
    }

    // Обработка движения (A и D теперь sf::Keyboard::Key::A / ::D)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        m_Square.moveLeft();
    }
    else
    {
        m_Square.stopLeft();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        m_Square.moveRight();
    }
    else
    {
        m_Square.stopRight();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        m_Square.moveUp();
    }
    else
    {
        m_Square.stopUp();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        m_Square.moveDown();
    }
    else
    {
        m_Square.stopDown();
    }
}