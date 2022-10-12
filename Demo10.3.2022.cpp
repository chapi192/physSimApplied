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
#include <cmath>
#include <iostream>
//#include "Vector3d.h" //Not working in 3d at this time.
#include "Vector2d.h"
#include "Dragging.h"
#include "Kinematics.h"

//allows for overloaded functions which are used in Vector2d
using namespace vecSpace;

//how often the computer refreshes the window per second
int frameRate = 100;


double timeElapsed = 0;

//not relevant at this time. This is used if we want our sim to be a specific time length, but this one runs until the window is closed for now
double simTime = 15;

//dt is set at a fraction of the framerate. So instead of updating where it should be an arbitrary number of times, it updates where we should be 
//exactly per frame
double dt = 1 / ((double)frameRate);

double error;

//size of the ball object
float radius = 20.0f;

bool grabbed;

Vector2d position;
Vector2d velocity;
Vector2d acceleration;
Vector2d screenSize;

//next 2 lines are related to calculating where we expect the ball to end up. kinCalc is that location, the kinematics object does the calculation
Kinematics kinematic;
Vector2d kinCalc;

//constructors of functions present in main to be used later, defined at the end of the code
void updateShape(sf::CircleShape &circle);
void Draw(sf::RenderWindow &window, sf::CircleShape &circle);

//-------------------------------------------------MAIN FUNCTION-----------------------------------------------------------//
int main()
{
	//Vector2d of the window size
	screenSize.setXYZ(1200, 800);
	//window is created.
	sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "Kinematics");
	window.setFramerateLimit(frameRate);

	//Let's start the ball in the middle of the screen. We must offset by the radius of the ball because 
	position.setXYZ(screenSize.x / 2 + radius, screenSize.y / 2 - radius);

	velocity.setXYZ(3, 0);
	acceleration.setXYZ(0, 9.81);

	//we run at 100fps, so we need to calculate by this porportion
	velocity = velocity * frameRate;
	acceleration = acceleration * frameRate;

	//calc where the actual result would be
	kinCalc = kinematic.kinematicsCalculator(position, velocity, acceleration, simTime);

	//our object of intrest. I chose a green ball.
	sf::CircleShape shape(radius);
	shape.setFillColor(sf::Color::Green);

	//variable used later in the checkDrag object
	int holdCount = 0;
	Dragging checkDrag;

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

		//Here I call the checkDrag object and evaluate the isDragging method. See the class for more detail.
		if (checkDrag.isDragging(event, holdCount))
		{
			//Since we are dragging the mouse, lets see where the mouse is in relation to our ball object
			float mouseX, mouseY, ballX, ballY;
			mouseX = sf::Mouse::getPosition(window).x;
			mouseY = sf::Mouse::getPosition(window).y;
			ballX = shape.getPosition().x + radius;
			ballY = shape.getPosition().y + radius;


			//distance from the mouse to the ball
			float magnitude = pow(pow((mouseX - ballX), 2) + pow((mouseY - ballY), 2), 0.5);

			//std::cout << " " << mouseX << " " << mouseY << " " << ballX << " " << ballY << " " << position.x << " " << position.y << std::endl;

			//If we are close enough to the ball, lets say that we have 'grabbed it' and are now setting it to follow our mouse
			if (magnitude <= 2 * radius + 10)
			{
				shape.setPosition(mouseX - radius, mouseY - radius);
				shape.setFillColor(sf::Color::Blue);
				position.setXYZ(mouseX - 2 * radius, mouseY - 2 * radius);
				velocity.setXYZ(0, 0);
				grabbed = true;
			}
		}
		else
		{
			grabbed = false;
		}

		//updateShape will move our shape according to its current conditions. We do not want to the computer to move it if we have grabbed it!
		if (!grabbed)
		{
			updateShape(shape);
		}

		//at the end of the loop, we draw the shape. See the draw method below for more
		Draw(window, shape);
	}

	return 0;

}

//takes in one circle object and moves it around on the screen. Recall our first few meetings to understand why we multiply by dt
void updateShape(sf::CircleShape &circle)
{

	timeElapsed += dt;

	position = position + (velocity * dt);
	velocity = velocity + (acceleration * dt);

	//if it is at the bottom or near the bottom, we should stop so it doesnt continue out of the screen.
	if (position.y < screenSize.y - 4 * radius)
	{
		circle.setPosition(position.x + radius, position.y + radius);
	}
	else { circle.setFillColor(sf::Color::Red); }
}

//draws everything
void Draw(sf::RenderWindow &window, sf::CircleShape &circle)
{
	//If we do not clear, we just draw the same thing on the same canvas over and over and over!
	window.clear();

	window.draw(circle);

	window.display();
}
