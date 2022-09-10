#include "Character.h"

Character::Character(const int lf, const int ma, const int ra, const bool b)
{
	life = lf;
	meleeAttack = ma;
	rangeAttack = ra;
	block = b;
}

Demon::Demon() : Character(demonLife, demonMeleeAttack, demonRangeAttack, 0) 
{
}

Knight::Knight() : Character(knightLife, knightMeleeAttack, knightRangeAttack, 0)
{
}

void Demon::AttackMelee(Character& c)
{
	if (Character::GetBlock() == true)
		return;
	else
		Character::SetLife(c.GetLife() - this->GetMelee());
}

void Knight::AttackMelee(Character& c)
{
	if (Character::GetBlock() == true)
		return;
	else
		Character::SetLife(c.GetLife() - this->GetMelee());
}
