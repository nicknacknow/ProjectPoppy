#pragma once
#include "Globals.h"

namespace Poppy {
	class Poppy
	{
	public:
		Direction direction = Direction::Up;
		int health = 100;
	}poppy;

	void guard(Attacker::Attack* attack) {
#ifdef DEVSTAT
		printf("DEVSTAT: Poppy::guard( %p )\n", &attack);
#endif
		attack->Clear();
	}

	void damage(Attacker::Attack* attack) {
#ifdef DEVSTAT
		printf("DEVSTAT: Poppy::damage( %p )\n", &attack);
#endif
		poppy.health -= attack->damage; // implement a level system here? * higher poppy lvl = less attack dmg, higher attack lvl = more attack dmg
	}

	// signals
	void onCollision(Attacker::Attack* attack) {
		if (flipDirection(attack->direction) == poppy.direction) {
			guard(attack);
		}
		else {
			damage(attack);
		}
	}
	void onGuard() {};
	void onDamage(int health);
}