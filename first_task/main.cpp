
// TurnBasedFighting.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Character.h"


int main()
{
	Knight Player;
	Demon Enemy;


	while ((Player.GetLife() != 0) || (Enemy.GetLife() != 0))
	{
		char input;
		Player.SetBlock(false);
		std::cout << "Your life: " << Player.GetLife() << "\t\t\tEnemy life: " << Enemy.GetLife() << std::endl;
		std::cout << "Your action (m - melee attack, r - range attack, b - block): ";
		input = std::cin.get();
		switch (input)
		{
		case 'm':
			Player.AttackMelee(Enemy);
			break;
		case 'r':
			Player.AttackRange(Enemy);
			break;
		case 'b':
			Player.SetBlock(true);
			break;
		}
		Enemy.SetBlock(false);
		std::cout << "Your life: " << Player.GetLife() << "\t\t\tEnemy life: " << Enemy.GetLife() << std::endl;
		std::cout << "Your enemy action (m - melee attack, r - range attack, b - block): ";
		input = std::cin.get();
		switch (input)
		{
		case 'm':
			Enemy.AttackMelee(Player);
			break;
		case 'r':
			Enemy.AttackMelee(Player);
			break;
		case 'b':
			Enemy.SetBlock(true);
			break;
		}
	}
}

