#include "pch.h"
#include "Character.h"
#include <iostream>

using namespace std;

void Character::EnterStats(int&p, int&s, string l) {
	for (;;) {
		int temp;
		system("cls");
		cout << "\nYou have " << p << " points left.\n" << "\nIntelect: " << intelect << "\nAgility:  " << agility << "\nStrength: " << strength << "\nStamina:  " << stamina;
		cout << "\n\n" << l;
		cin >> temp;

		if (temp >= 0 && temp <= 20) {
			if (p - temp >= 0) {
				p -= temp;
				s = temp;
				getchar();
				system("cls");
				
				break;
			}
			else if (p - temp < 0) {
				cout << "\nYou don't have that many points left\n";
				getchar(); getchar();
			}
		}
	}
}

Character::Character(string n, int i, int s, int a, int stam)
{
	intelect = i; strength = s, agility = a, stamina = stam;
	int points = 20;
	cout << "You have a dream. \n";
	cout << "What is your name anon? "; cin >> name;
	cout << "You have "<<points<<" points to redistribute. Choose very wisely " << name << " for there will be no return.\n";
	getchar(); getchar();
	
	EnterStats(points, intelect, "Intelect: ");
	EnterStats(points, agility, "Agility: ");
	EnterStats(points, strength, "Strength: ");
	EnterStats(points, stamina, "Stamina: ");
}


Character::~Character()
{
}
