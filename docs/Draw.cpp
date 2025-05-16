#include "Engine.h"

void Engine::draw()
{
    m_Window.clear(Color::White);

    m_Window.draw(m_BackgroundSprite);

    m_Window.draw(m_Square.getSprite());
    m_Window.draw(m_Rectangle.getShape());

    m_Window.display();
}