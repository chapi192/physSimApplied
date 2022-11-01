#include "Scene.h"

Scene::Scene(int frameRate, vec2 p_acc)
	: dt{ 1.0f / frameRate }, acc{ p_acc } {
	float radius = 20.0f;
	circles.push_back({ radius, {120,  20}, sf::Color::Green });
	circles.back().setVel({ -200, 0 });
	circles.push_back({ radius, {320, 180}, sf::Color::Blue });
	circles.back().setVel({ 300, -80 });
}

void Scene::update(const sf::RenderWindow& window) {
	timeElapsed += dt;

	for (auto& c : circles) {
		c.vel += acc * dt;
		c.move(c.vel * dt);

		vec2 min = c.getPos() - vec2{ c.getRadius(), c.getRadius() };
		vec2 max = c.getPos() + vec2{ c.getRadius(), c.getRadius() };
		if (min.x < 0) {
			c.vel.x *= -1;
			c.move({ -min.x, 0 });
		}
		if (min.y < 0) {
			c.vel.y *= -1;
			c.move({ 0, -min.y });
		}
		vec2 adjMax = max - vec2(window.getSize());
		if (adjMax.y > 0) {
			c.vel.y *= -1;
			c.move({ 0, -adjMax.y });
		}
		if (adjMax.x > 0) {
			c.vel.x *= -1;
			c.move({ -adjMax.x, 0 });
		}
	}
}

void Scene::SFML_draw(sf::RenderWindow& window) {
	//clean the window, so previous frames are not visible
	window.clear();

	// draw all of the circles in scene
	for (auto& c : circles) {
		window.draw(c);
	}

	//display drawn elements!
	window.display();
}
