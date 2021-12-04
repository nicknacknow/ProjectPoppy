#pragma once
#include "Globals.h"

namespace Attacker {
	enum AttackType { Normal, Reverse }; // describes types of attack
	class Attack
	{
	public:
		Direction direction;
		AttackType type;
		int damage;

		void Clear() {
			delete this;
		}
	private:
	};

	Attack* newAttack(int damage = 10, Direction direction = Direction::Down, AttackType type = Normal) {
		Attack* attack = new Attack;
		attack->direction = direction;
		attack->damage = damage;
		attack->type = type;

		return attack;
	}
}