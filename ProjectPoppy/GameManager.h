#pragma once
#include "Globals.h"
#include <chrono>
#include <vector>

void clear() {
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	std::cout << "\x1B[2J\x1B[H";
}

std::vector<Attacker::Attack*> attacks;

class GameManager {
public:
	void removeAttack(Attacker::Attack* attack) {
		attacks.erase(std::remove(attacks.begin(), attacks.end(), attack), attacks.end());
	}

	void main() {
		auto lastRender = std::chrono::system_clock::now();
		while (true) {
			auto now = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = now - lastRender;
			lastRender = std::chrono::system_clock::now();
			
			step(elapsed_seconds.count());
		}
	}

	void input() {
		if (isKeyPressed(VK_UP)) Poppy::poppy.direction = Up;
		else if (isKeyPressed(VK_DOWN)) Poppy::poppy.direction = Down;
		else if (isKeyPressed(VK_LEFT)) Poppy::poppy.direction = Left;
		else if (isKeyPressed(VK_RIGHT)) Poppy::poppy.direction = Right;
	}

	void step(float dT) {
		input();
		//printf("%d\n", Poppy::poppy.direction);
		//printf("%f\n", dT);

		for (Attacker::Attack* attack : attacks) // rlly need to fix this - removing and adding attacks to list. perhaps list? https://stackoverflow.com/questions/596162/can-you-remove-elements-from-a-stdlist-while-iterating-through-it
		{
			if ((int)attack < 0) continue; // stupid check because sometimes attack has already been deleted
		//	printf("time left : %f\n", (attack->distanceFromPoppy - (attack->radius + Poppy::poppy.radius)) / attack->velocity);
			attack->distanceFromPoppy -= attack->velocity * dT;

			printf(""); // for some reason this is needed to update the stuff ? not sure why - pretty unstable atm

			if (Poppy::checkCollision(attack)) {
				printf("collision ! \n");
				Poppy::onCollision(attack, attacks);
				//removeAttack(attack);
			}
		}
		
		// Sleep (1000 / frequency);
	}
private:
	bool isKeyPressed(BYTE vk) {
		return GetAsyncKeyState(vk) & 1;
	}

	int frequency = 1; // 1 action per second
};