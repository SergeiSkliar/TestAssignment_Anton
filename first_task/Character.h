#pragma once

#include <iostream>

const int demonLife = 125;
const int demonMeleeAttack = 10;
const int demonRangeAttack = 30;

const int knightLife = 150;
const int knightMeleeAttack = 20;
const int knightRangeAttack = 10;

class Character
{
public:
	Character(const int lf = 0, const int ma = 0, const int ra = 0, const bool b = false);
	virtual ~Character() {}

	int GetLife() const { return life; }
	void SetLife(int val) { life = val; }
	int GetMelee() const { return meleeAttack; }
	int GetBlock() const { return block; }
	void SetBlock(bool b) { block = b; }

	virtual void AttackMelee(Character& c) = 0;
	virtual void AttackRange(Character& c) = 0;

	void print() const { std::cout << this->GetLife(); }

protected:
	int life;
	int meleeAttack;
	int rangeAttack;
	bool block;
};

class Demon : public Character
{
public:
	Demon();
	virtual ~Demon() {}

	void AttackMelee(Character& c) override;
	void AttackRange(Character& c) override;
	void Block(bool b) { Character::SetBlock(b); }

private:

};

class Knight : public Character
{
public:
	Knight();
	virtual ~Knight() {}

	void AttackMelee(Character& c) override;
	void AttackRange(Character& c) override;
	void Block(bool b) { Character::SetBlock(b); }

private:
};
