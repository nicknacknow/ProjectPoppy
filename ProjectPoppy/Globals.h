#pragma once
#include <iostream>

#define DEVSTAT

enum Direction { Down, Up, Left, Right }; // describes direction of attack

Direction flipDirection(Direction d) {
	return Direction(d + ((d % 2 == 0) ? 1 : -1));
}

#include "Attacker.h"
#include "Poppy.h"