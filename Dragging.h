#pragma once
#include <SFML/Graphics.hpp> //required to pass an event

class Dragging
{
public:
	int holdCount;

	//constructor
	Dragging();

	//function which evaluates weather or not we are holding down the mouse.
	bool isDragging(sf::Event &event, int &holdCount);

};

