#pragma once
#include <SFML/Graphics.hpp> //required to pass an event

class Dragging
{
public:
	int holdCount;

	Dragging();

	bool isDragging(sf::Event &event, int &holdCount);

};

