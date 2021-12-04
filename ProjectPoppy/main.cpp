#include <Windows.h>
#include <iostream>

#include "Poppy.h"

int main() {
	Attacker::Attack* attack = Attacker::newAttack(Down);

	Poppy::onCollision(attack);

	std::cin.get();
	return 1;
}