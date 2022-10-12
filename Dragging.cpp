#include "Dragging.h"
#include <SFML/Graphics.hpp> //required to pass an event
#include <iostream>

Dragging::Dragging() : holdCount(holdCount)
{
	//each time we make an instance, we want to make sure that hold count is 0
	holdCount = 0;
}

//
bool Dragging::isDragging(sf::Event &event, int &holdCount /*IMPORTANT: we want to get the value from the holdCount in main, so we use '&'. Otherwise, we would have a copy of holdCount*/)
{
	//Explanation of the following logic: If we are clicking the mouse, add one to the counter. If we release the mouse, reset the counter. Return false since we cannot release the mouse
	//but also be holding it. If the hold count is greater than 3, we have held the mouse for more than 3 frames. Probably clicking and dragging, so return true. 
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