//----------------------------------------------------IMPORTANT NOTES--------------------------------------------------//
/*
you may see some caution signs or warnings that are NOT ERRORS in the debug menu. Compiler is a beta, you can ignore these unless they screw up the
code. this is good for now.

The coordinates of an SFML window move accross the screen left to right, and down the screen top to bottom. This means that to the right is positive
and so is down. For example, the coordinate 100, 100 in SFML would 'normaly' be the cartesian coordinate 100, -100. DOWN IS POSITIVE!

Objects are also drawn left to right, top to bottom. This means that a square of length and with 10 would be drawn such that its top left coordinate
is 0,0 but its bottom right is 10,10. To draw the square at a particular location, we have to offset its coordinates.
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>

using vec2 = sf::Vector2f;

//how often the computer refreshes the window per second
int frameRate = 100;
#include "Scene.h"

void SFML_eventHandler(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

int main() {
	//window is created.
	sf::RenderWindow window(sf::VideoMode(600, 300), "Kinematics");
	window.setFramerateLimit(frameRate);

	Scene scene{ { 0.f, 9.81f } };
	while (window.isOpen()) {
		SFML_eventHandler(window);
		scene.update(window);
		scene.SFML_draw(window);
	}

	return 0;

}