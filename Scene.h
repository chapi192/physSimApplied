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

	void move(const vec2& dpos) {
		sf::CircleShape::move(dpos.x, dpos.y);
	}
};

struct Scene {
	float dt = 1.0 / frameRate;
	float timeElapsed = 0;
	vec2 acc;
	std::vector<Circle> circles;

	Scene(vec2 p_acc)
		: acc{ p_acc } {
		float radius = 20.0f;
		circles.push_back({ radius, {120,  20}, sf::Color::Green });
		circles.push_back({ radius, {320, 180}, sf::Color::Blue });
	}

	void update(const sf::RenderWindow& window) {
		timeElapsed += dt;

		for (auto& c : circles) {
			c.vel += acc * dt;
			c.move(c.vel * dt);
		}
	}

	void SFML_draw(sf::RenderWindow& window) {
		//clean the window, so previous frames are not visible
		window.clear();

		// draw all of the circles in scene
		for (auto& c : circles) {
			window.draw(c);
		}

		//display drawn elements!
		window.display();
	}
};
