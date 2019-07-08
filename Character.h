#pragma once
#include <string>
#include <iostream>
#include <windows.h>

class Character
{
private:
	friend class Enemy;
	friend class Goblin;
	friend class NewGame;
	
	//Arrays
	int* arrx = new int[100];
	int* arry = new int[100];

	//Attributes
	std::string name;
	int intelect, strength, stamina, luck; //Statistics
	int armor, hp,maxhp, mana,maxmana, lvl, exp, exp2, energy; 
	int gold;
	int xpos, ypos; //Location
	int nom; //Number of moves
	int ax, ay; //Table index

	//Methods
	int getLvl();
	int getMaxHP();
	int getMaxMana();
	int getMaxExp();
	int getMaxEnergy();
	int Attack(); //Attacks

	void EnterStats(int&p, int&s, std::string l);	//Enters stats
	void LevelUp();	//Levels Up, allows to add stats
	void Move();
	void Rest();
	void CharacterSheet();
	void appendArrX(int* arrx);
	void appendArrXSame(int* arrx);
	void appendArrY(int* arry);
	void appendArrYSame(int* arry);
	void showArr(int* arr, char x, int index);

	bool notDead();
	bool wasYouHere(int*arrx, int*arry);
	bool isNoMoves100();

public:
	Character(std::string="Anon", int=0, int=0, int=0, int=0, int = 1);
	~Character();
};

