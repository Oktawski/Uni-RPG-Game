#pragma once
#include <string>
class Player
{
private:
	int stamina, intelect, stress, charisma;
	int energy;
	std::string name;
public:
	void Show();
	void EnterStats();
	Player(std::string ="Anon", int=5, int=5, int=5, int=5, int=100);
	~Player();
};

