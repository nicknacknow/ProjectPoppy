#include <Windows.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include "Globals.h"

int main() {
	/*Attacker::Attack* attack = Attacker::newAttack();
	std::vector<Attacker::Attack*> attacks = { attack };
	Poppy::onCollision(attack);
	printf("%d\n", attacks.size()); // since size is 1, will have to make attacks in GameManager and handle things in there - so they can be removed
	*/

	GameManager gameManager;
	std::thread mainLoop([](GameManager gameManager) { gameManager.main(); }, gameManager);

	Sleep(1000);

	for (int i = 0; i < 200; i++) {
		Attacker::Attack* attack = Attacker::newAttack();
		attack->direction = Direction::Up;
		attacks.emplace_back(attack);

		//Sleep(500);
	}

	std::cin.get();
	return 1;
}