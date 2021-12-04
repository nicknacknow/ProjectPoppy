#include <Windows.h>
#include <iostream>

#include "Poppy.h"

int main() {
	Attacker::Attack* attack = Attacker::newAttack(Up);

	Poppy::onCollision(attack);

	std::cin.get();
	return 1;
}