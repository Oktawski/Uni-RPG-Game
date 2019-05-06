#pragma once
class Enemy
{
private:

	int intelect, strength, stamina, agility; //statistics
	int armor, hp;
public:
	void ShowStats();
	Enemy(int=1, int =1, int=1, int=1, int =1, int=1);
	~Enemy();
};

