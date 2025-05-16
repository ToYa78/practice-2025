#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Rectangle
{

private:
	Vector2f r_Position;
	RectangleShape rectangle;
	sf::Vector2f r_Velocity;
	float r_Mass;
	float r_Restitution;
public:
	Rectangle();
	void update(float dt);
	void applyForce(const sf::Vector2f& force);
	float getRestitution() const { 
		return r_Restitution;
	}
	sf::RectangleShape& getShape();

	bool checkCollision(const sf::FloatRect& otherBounds) const;
};