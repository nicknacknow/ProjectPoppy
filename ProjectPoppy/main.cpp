#include <Windows.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include "Globals.h"
#include "LinkedTable.h"

int main() {
	/*Attacker::Attack* attack = Attacker::newAttack();
	std::vector<Attacker::Attack*> attacks = { attack };
	Poppy::onCollision(attack);
	printf("%d\n", attacks.size()); // since size is 1, will have to make attacks in GameManager and handle things in there - so they can be removed
	*/

	LinkedTable<int> table;

	table.AddValue(1); // 0
	table.AddValue(2); // 1
	table.AddValue(3);
	//printf("%p\n", table.start->val);
	printf("lolol : %d\n", table.count());
	for (int i = 0; i < table.count(); i++) {
		printf("	%d - %d\n", i, table.getValue(i));
	}
	table.RemoveValue(1);
	printf("lolol : %d\n", table.count());

	for (int i = 0; i < table.count(); i++) {
		printf("	%d - %d\n",i, table.getValue(i));
	}

	GameManager gameManager;

	//Sleep(1000);

	Attacker::Attack* first = nullptr;
	Attacker::Attack* last = nullptr;

	for (int i = 0; i < 100; i++) {
		Attacker::Attack* attack = Attacker::newAttack();
		if (first == nullptr) first = attack;
		else {
			last->next = attack;
		}
		attack->direction = Direction::Up;
		last = attack;
		attacks.emplace_back(attack);

		//Sleep(500);
	}

	int lol = 1;
	Attacker::Attack* now = first;
	while (now != last) {
		lol++;
		now = now->next;
	}

	printf("%d\n", lol);

	gameManager.removeAttack(attacks[42]);
	now = first;
	lol = 1;
	while (now != last) {
		lol++;
		now = now->next;
	}
	printf("%d\n", lol);


	//std::thread mainLoop([](GameManager gameManager) { gameManager.main(); }, gameManager);

	std::cin.get();
	return 1;
}