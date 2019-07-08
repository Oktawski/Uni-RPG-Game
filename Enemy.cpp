#include "pch.h"
#include "Enemy.h"

using namespace std;

//Checks stats of enemy, will be removed later
void Enemy::ShowStats()	
{
	std::cout <<"\nName: "<<name<< "\nIntelect: " << intelect << "\nStrength: " << strength << "\nStamina: " << stamina << "\nArmor: " << armor << "\nHP: " << hp << std::endl;
}
//Checks if enemy is dead
bool Enemy::notDead() {
	if (this->hp > 0) {
		return true;
	}
}
//Enemy attack
int Enemy::Attack() {
	return (rand() % (this->strength)*(this->lvl) + 1);
}
int Enemy::MagicalAttack() {
	return ((rand() % this->intelect)* (this->lvl) + 1);
}
int Enemy::getGold() {
	return (rand() % (this->lvl * 2));
}

Enemy::Enemy(std::string nam, int lv, int hap)	
{
	xpos = (rand() % 10);
	ypos = (rand() % 10);
	name = nam;
	lvl = lv;
	name = nam;
	intelect = (rand()%lvl)+ 1;
	strength = (rand() % lvl) + 1;
	stamina = (rand() % lvl) + 1;
	armor = (rand() % lvl);
	hp = lvl*(rand() % lvl) + hap;
	exp = (rand() % lvl + 2);
	gold = getGold();
}
Enemy::~Enemy()
{
}
