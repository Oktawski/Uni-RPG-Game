#include "pch.h"
#include "Player.h"
#include <iostream>
using namespace std;

void Player::EnterStats() {
	int points = 10;
	cout << "You have a dream. \n";
	cout << "What is your name anon? "; cin>>name;
	cout << "You have 10 points to redistribute. Choose very wisely "<<name<<" for there will be no return.\n";
	cout << "Intelect: "; cin >> intelect;
	points -= intelect;
	cout << "Charisma: "; cin >> charisma;
	points -= charisma;
	cout << "Stress: "; cin >> stress;
	points -= stress;
	cout << "Stamina: "; cin >> stamina;
	points -= stamina;
	cout << points;
	
}
void Player::Show() {
	cout << name << endl << intelect << " " << charisma << " " << stress << " " << stamina << " energy: " << energy;
}

Player::Player(string n, int s, int i, int st, int c, int e)
{
	name = n;
	stamina = s;
	intelect = i;
	stress = st;
	charisma = c;
	energy = e;
}


Player::~Player()
{
}
