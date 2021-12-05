#pragma once
#include "Globals.h"
#include <chrono>
#include <vector>

void clear() {
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	std::cout << "\x1B[2J\x1B[H";
}

class GameManager {
public:
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
		
		// Sleep (1000 / frequency);
	}
private:
	bool isKeyPressed(BYTE vk) {
		return GetAsyncKeyState(vk) & 1;
	}
	
	std::vector<Attacker::Attack*> attacks;
	int frequency = 1; // 1 action per second
};