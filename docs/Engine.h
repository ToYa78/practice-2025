#include "Square.h";
#include "Rectangle.h";
#include <SFML/Window.hpp>

using namespace sf;

class Engine
{
private:

    RenderWindow m_Window;

    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
    Rectangle m_Rectangle;

    Square m_Square;

    void input();
    void update(float dtAsSeconds);
    void draw();

public:
    Engine();

    void handleCollisions();

    void start();

};