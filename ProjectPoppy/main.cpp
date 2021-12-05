#include <Windows.h>
#include <iostream>
#include <vector>
#include <chrono>

#include "Globals.h"

int main() {
	Attacker::Attack* attack = Attacker::newAttack();
	std::vector<Attacker::Attack*> attacks = { attack };
	Poppy::onCollision(attack);
	printf("%d\n", attacks.size()); // since size is 1, will have to make attacks in GameManager and handle things in there - so they can be removed
	

	//GameManager gameManager;
	//gameManager.main();

	std::cin.get();
	return 1;
}