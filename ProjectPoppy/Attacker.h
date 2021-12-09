#pragma once
#include "Globals.h"

namespace Attacker {
	enum AttackType { Normal, Reverse }; // describes types of attack
	class Attack
	{
	public:
		Attack() {}
		Attack(float rad,float dist, float vel, float dmg, Direction dir, AttackType _type) : radius(rad), distanceFromPoppy(dist), velocity(vel), damage(dmg), direction(dir), type(_type) {}
		Direction direction;
		AttackType type;
		float velocity; // speed = distance/time ,, we will be able to calculate distance from poppy 
		float damage;
		float distanceFromPoppy;
		float radius;

		void Clear() {
			//delete this;
		}
	private:
	};

	Attack* newAttack(float radius = 5.f, float distanceFromPoppy = 50.f, float velocity = 10.f, float damage = 10.f, Direction direction = Direction::Down, AttackType type = Normal) {
		Attack* attack = new Attack(radius, distanceFromPoppy, velocity, damage, direction, type);

		return attack;
	}
}