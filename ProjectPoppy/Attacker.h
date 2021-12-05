#pragma once
#include "Globals.h"

namespace Attacker {
	enum AttackType { Normal, Reverse }; // describes types of attack
	class Attack
	{
	public:
		Attack() {}
		Attack(float vel, int dmg, Direction dir, AttackType _type) : velocity(vel), damage(dmg), direction(dir), type(_type) {}
		Direction direction;
		AttackType type;
		float velocity; // speed = distance/time ,, we will be able to calculate distance from poppy 
		int damage;

		void Clear() {
			delete this;
		}
	private:
	};

	Attack* newAttack(float velocity = 10.f, int damage = 10, Direction direction = Direction::Down, AttackType type = Normal) {
		Attack* attack = new Attack(velocity, damage, direction, type);

		return attack;
	}
}