#pragma once
#include <string>

class Character
{
private:
	std::string name;
	int intelect, strength, stamina, agility; //statistics
	int armor, hp, mana; 

	void EnterStats(int&p, int&s, std::string l);

public:
	Character(std::string="Anon", int=0, int=0, int=0, int=0);
	~Character();
};

