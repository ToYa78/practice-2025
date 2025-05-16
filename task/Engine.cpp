#include "Engine.h"
#include "iostream"

Engine::Engine() : m_BackgroundTexture(), m_BackgroundSprite(m_BackgroundTexture)
{

    m_Window = sf::RenderWindow(sf::VideoMode({ 1920, 1080 }), "Simple Game Engine");
    m_Window.setFramerateLimit(60);
    sf::Texture texture;

    if (!m_BackgroundTexture.loadFromFile("background.jpg")) {
        throw std::runtime_error("Failed to load background.jpg");
    }
    m_BackgroundSprite.setTexture(m_BackgroundTexture, true);
}

void Engine::handleCollisions() {
    sf::FloatRect SquareBounds = m_Square.getSprite().getGlobalBounds();
    sf::FloatRect rectBounds = m_Rectangle.getShape().getGlobalBounds();

    if (SquareBounds.findIntersection(rectBounds).has_value()) {

        sf::Vector2f SquareCenter = {
            SquareBounds.position.x + SquareBounds.size.x / 2,
            SquareBounds.position.y + SquareBounds.size.y / 2
        };

        sf::Vector2f rectCenter = {
            rectBounds.position.x + rectBounds.size.x / 2,
            rectBounds.position.y + rectBounds.size.y / 2
        };

        sf::Vector2f pushDirection = rectCenter - SquareCenter;

        float length = std::sqrt(pushDirection.x * pushDirection.x + pushDirection.y * pushDirection.y);
        pushDirection /= length;

        float forceMagnitude = 500.0f * m_Rectangle.getRestitution();
        m_Rectangle.applyForce(pushDirection * forceMagnitude);

        m_Rectangle.getShape().move(pushDirection * 7.f);
    }
}

void Engine::start()
{
    Clock clock;

    while (m_Window.isOpen())
    {
        Time dt = clock.restart();

        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        handleCollisions();
        draw();
    }
}
