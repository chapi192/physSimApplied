#include <SFML/Graphics.hpp>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>
//#include "Vector3d.h"
#include "Vector2d.h"
#include "Dragging.h"
#include "Kinematics.h"

using namespace vecSpace;

int frameRate = 100;

double timeElapsed = 0;
double simTime = 15;
double dt = 1 / ((double)frameRate);

double error;
float radius = 20.0f;

bool grabbed;

Vector2d position;
Vector2d velocity;
Vector2d acceleration;
Vector2d screenSize;

Kinematics kinematic;
Vector2d kinCalc;

void updateShape(sf::CircleShape &circle);
void Draw(sf::RenderWindow &window, sf::CircleShape &circle);

int main()
{
	//initialize window
	screenSize.setXYZ(1200, 800);
	sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "Kinematics");
	window.setFramerateLimit(frameRate);

	//define vectors
	position.setXYZ(screenSize.x / 2 + radius, screenSize.y / 2 - radius);

	velocity.setXYZ(3, 0);
	acceleration.setXYZ(0, 9.81);

	//we run at 100fps, so we need to calculate by this porportion
	velocity = velocity * frameRate;
	acceleration = acceleration * frameRate;

	//calc where the actual result would be
	kinCalc = kinematic.kinematicsCalculator(position, velocity, acceleration, simTime);

	//our object
	sf::CircleShape shape(radius);
	shape.setFillColor(sf::Color::Green);

	int holdCount = 0;
	Dragging checkDrag;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
		}

		if (checkDrag.isDragging(event, holdCount))
		{
			float mouseX, mouseY, ballX, ballY;
			mouseX = sf::Mouse::getPosition(window).x;
			mouseY = sf::Mouse::getPosition(window).y;
			ballX = shape.getPosition().x + radius;
			ballY = shape.getPosition().y + radius;

			float magnitude = pow(pow((mouseX - ballX), 2) + pow((mouseY - ballY), 2), 0.5);

			//std::cout << " " << mouseX << " " << mouseY << " " << ballX << " " << ballY << " " << position.x << " " << position.y << std::endl;


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

		if (!grabbed)
		{
			updateShape(shape);
		}

		Draw(window, shape);
	}

	return 0;

}

//updates
void updateShape(sf::CircleShape &circle)
{

	timeElapsed += dt;

	position = position + (velocity * dt);
	velocity = velocity + (acceleration * dt);

	if (position.y < screenSize.y - 4 * radius)
	{
		circle.setPosition(position.x + radius, position.y + radius);
	}
	else { circle.setFillColor(sf::Color::Red); }
}

//draws everything
void Draw(sf::RenderWindow &window, sf::CircleShape &circle)
{
	window.clear();

	window.draw(circle);

	window.display();
}
