#include "Dragging.h"
#include <SFML/Graphics.hpp> //required to pass an event
#include <iostream>

Dragging::Dragging() : holdCount(holdCount)
{
	holdCount = 0;
}

bool Dragging::isDragging(sf::Event &event, int &holdCount)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		holdCount += 1;
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		holdCount = 0;
		return false;
	}
	if (holdCount > 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}