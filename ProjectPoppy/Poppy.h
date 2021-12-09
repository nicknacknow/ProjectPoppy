#pragma once
#include "Globals.h"

namespace Poppy {
	class Poppy
	{
	public:
		Direction direction = Direction::Up;
		float health = 100;
		float radius = 10.f;
	}poppy;

	// signals
	void onCollision(Attacker::Attack* attack);
	void onGuard(Attacker::Attack* attack);
	void onDamage(Attacker::Attack* attack);

	bool checkCollision(Attacker::Attack* attack) {
		return attack->distanceFromPoppy < attack->radius + poppy.radius;
	}

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
	void onCollision(Attacker::Attack* attack, std::vector<Attacker::Attack*> &attacks) {
		if (flipDirection(attack->direction) == poppy.direction)
			guard(attack);
		else
			damage(attack);

		attack->Clear();
	}
	void onGuard(Attacker::Attack* attack) {}
	void onDamage(Attacker::Attack* attack) {}
}