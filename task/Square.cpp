#include "Square.h"
#include "Engine.h"

Square::Square() : m_Texture(), m_Sprite(m_Texture) {

    if (!m_Texture.loadFromFile("bob.png")) {
        throw std::runtime_error("Failed to load texture: bob.png");
    }
    m_Sprite.setTexture(m_Texture, true);

    m_Speed = 400;
    m_Position = { 300, 300 };
    m_Sprite.setPosition(m_Position);
}



sf::Sprite& Square::getSprite() {
    return m_Sprite;
}

void Square::moveLeft()
{
    m_LeftPressed = true;
}

void Square::moveRight()
{
    m_RightPressed = true;
}

void Square::stopLeft()
{
    m_LeftPressed = false;
}

void Square::stopRight()
{
    m_RightPressed = false;
}

void Square::moveDown()
{
    m_DownPressed = true;
}

void Square::moveUp()
{
    m_UpPressed = true;
}

void Square::stopDown()
{
    m_DownPressed = false;
}

void Square::stopUp()
{
    m_UpPressed = false;
}

void Square::update(float elapsedTime)
{
    if (m_RightPressed)
    {
        m_Position.x += m_Speed * elapsedTime;
    }

    if (m_LeftPressed)
    {
        m_Position.x -= m_Speed * elapsedTime;
    }

    if (m_UpPressed)
    {
        m_Position.y -= m_Speed * elapsedTime;
    }

    if (m_DownPressed)
    {
        m_Position.y += m_Speed * elapsedTime;
    }

    m_Sprite.setPosition(m_Position);

}