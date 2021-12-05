#pragma once
#include "Globals.h"

namespace Poppy {
	class Poppy
	{
	public:
		Direction direction = Direction::Up;
		int health = 100;
	}poppy;

	// signals
	void onCollision(Attacker::Attack* attack);
	void onGuard(Attacker::Attack* attack);
	void onDamage(Attacker::Attack* attack);

	void guard(Attacker::Attack* attack) {
#ifdef DEVSTAT
		printf("DEVSTAT: Poppy::guard( %p )\n", &attack);
#endif

		onGuard(attack);
	}

	// implement a level system here? * higher poppy lvl = less attack dmg, higher attack lvl = more attack dmg
	void damage(Attacker::Attack* attack) {
#ifdef DEVSTAT
		printf("DEVSTAT: Poppy::damage( %p )\n", &attack);
#endif
		poppy.health -= attack->damage;
		onDamage(attack);
	}

	// signals
	void onCollision(Attacker::Attack* attack) {
		if (flipDirection(attack->direction) == poppy.direction)
			guard(attack);
		else
			damage(attack);

		attack->Clear();
	}
	void onGuard(Attacker::Attack* attack) {}
	void onDamage(Attacker::Attack* attack) {}
}