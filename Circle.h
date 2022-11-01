#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using vec2 = sf::Vector2f;

// implementing Circle as SFML's CircleShape to expand on it with physics
struct Circle : public sf::CircleShape {
	vec2 vel{};

	Circle(float radius, vec2 pos, sf::Color c)
		: sf::CircleShape{ radius } {
		setFillColor(c);
		setPosition(pos.x - radius, pos.y - radius);
	}

	vec2 getPos() {
		return getPosition() + vec2{ getRadius(), getRadius() };
	}

	void setVel(const vec2& p_vel) {
		vel = p_vel;
	}

	void move(const vec2& dpos) {
		sf::CircleShape::move(dpos.x, dpos.y);
	}
};
