//----------------------------------------------------IMPORTANT NOTES--------------------------------------------------//
/*
you may see some caution signs or warnings that are NOT ERRORS in the debug menu. Compiler is a beta, you can ignore these unless they screw up the 
code. this is good for now.

The coordinates of an SFML window move accross the screen left to right, and down the screen top to bottom. This means that to the right is positive
and so is down. For example, the coordinate 100, 100 in SFML would 'normaly' be the cartesian coordinate 100, -100. DOWN IS POSITIVE!

Objects are also drawn left to right, top to bottom. This means that a square of length and with 10 would be drawn such that its top left coordinate
is 0,0 but its bottom right is 10,10. To draw the square at a particular location, we have to offset its coordinates.
*/


//Libraries we want to include:
#include <SFML/Graphics.hpp>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>

//how often the computer refreshes the window per second
int frameRate = 100;

double timeElapsed = 0;

//dt is set at a fraction of the framerate. So instead of updating where it should be an arbitrary number of times, it updates where we should be 
//exactly per frame
double dt = 1 / ((double)frameRate);

//size of the ball object
float radius = 20.0f;

//-------------------------------------------------MAIN FUNCTION-----------------------------------------------------------//
int main()
{
	//window is created.
	sf::RenderWindow window(sf::VideoMode(600, 300), "Kinematics");
	window.setFramerateLimit(frameRate);

	//creating our ball. It is green!
	sf::CircleShape shape(radius);
	shape.setFillColor(sf::Color::Green);

	//the ball will start at the top left. Remember to offset if you want to move according to its center!
	shape.setPosition(0, 0);

	while (window.isOpen())
	{
		//SFML stuff. This block just means that if we press escape or hit the close window button on the window, close the window.
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
		}

		//clean the window, so previous frames are not visible
		window.clear();

		//draw the shape!
		window.draw(shape);

		//display drawn elements!
		window.display();
		
	}

	return 0;

}