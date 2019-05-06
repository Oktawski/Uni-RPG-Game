#include "pch.h"
#include "Enemy.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void Enemy::ShowStats()	//Checks stats of enemy 
{
	std::cout << "\nIntelect: " << intelect << "\nStrength: " << strength << "\nStamina: " << stamina << "\nAgility: " << 
		agility << "\nArmor: " << armor << "\nHP: " << hp << std::endl;
}

Enemy::Enemy(int intel, int str, int stam, int agi, int arm, int hpo)	//Constructor of enemy
{
	
	intelect = (rand()%intel)+ 1;
	strength = (rand() % str) + 1;
	stamina = (rand() % stam) + 1;
	agility = (rand() % agi) + 1;
	armor = (rand() % arm);
	hp = (rand() % hpo) + 50;
}


Enemy::~Enemy()
{
}
