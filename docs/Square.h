#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Square
{
private:

    Vector2f m_Position;

    Sprite m_Sprite;

    Texture m_Texture;

    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_DownPressed;
    bool m_UpPressed;

    float m_Speed;

public:

    Square();

    sf::Sprite& getSprite();

    void moveLeft();

    void moveRight();

    void moveDown();

    void moveUp();

    void stopDown();

    void stopUp();

    void stopLeft();

    void stopRight();

    void update(float elapsedTime);

};