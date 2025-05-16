#include "Rectangle.h"
#include "Engine.h"

Rectangle::Rectangle() : rectangle({ 200.f, 200.f })
{
    r_Position = { 600, 400 };
    rectangle.setPosition(r_Position);
    rectangle.setFillColor(Color(250, 50, 50));
    r_Velocity = { 0.f, 0.f };
    r_Mass = { 10.0f };
    r_Restitution = { 0.7f };
}

void Rectangle::update(float dt) {
    rectangle.move(r_Velocity * dt);

    r_Velocity *= 0.98f;
}

void Rectangle::applyForce(const sf::Vector2f& force) {
    r_Velocity += force / r_Mass;
}

RectangleShape& Rectangle::getShape(){
    return rectangle;
}

bool Rectangle::checkCollision(const sf::FloatRect& otherBounds) const {
    auto intersection = rectangle.getGlobalBounds().findIntersection(otherBounds);
    return intersection.has_value(); 
}