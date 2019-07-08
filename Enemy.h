#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
#include "Character.h"

class Enemy
{
private:
	friend class NewGame;
	friend class Character;
	friend class Goblin;

	//Attributes
	std::string name;
	int intelect, strength, stamina; //statistics
	int armor, hp, lvl, exp;
	int xpos, ypos;
	int gold;

	//Methods
	int Attack();
	int MagicalAttack();
	int getGold();
	
	bool notDead();
public:
	void ShowStats();
	Enemy(std::string="Mob", int=1, int=20);
	~Enemy();
};

