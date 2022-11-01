#pragma once
#include "Circle.h"
#include <SFML/System.hpp>

using vec2 = sf::Vector2f;

// Handles the circle objects: creating, updating, and drawing
class Scene {
private:
	float dt;
	float timeElapsed = 0;
	vec2 acc;
	std::vector<Circle> circles;
public:
	Scene(int frameRate, vec2 p_acc);

	void update(const sf::RenderWindow& window);

	void SFML_draw(sf::RenderWindow& window);
};
