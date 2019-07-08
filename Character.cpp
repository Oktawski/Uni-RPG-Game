#include "pch.h"
#include "Character.h"

using namespace std;

void Character::EnterStats(int&p, int&s, string l) {
	for (;;) {
		int temp;
		system("cls");
		cout << "\nYou have " << p << " points left.\n" << "\nIntelect: " << intelect << "\nLuck:  " << luck << "\nStrength: " << strength << "\nStamina:  " << stamina;
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
void Character::LevelUp() {
	//Adding point
	for (;;) {
		char temp;
		system("cls");
		cout << "\nLevel Up!";
		cout << "\nYou have " << 1 << " points left.\n" << "\n1. Intelect: " << intelect << "\n2. Luck:  " << luck << "\n3. Strength: " << strength << "\n4. Stamina:  " << stamina;
		cout << "\nChoose which stat you want to increase\n";
		cin >> temp;
		switch (temp) {
		case '1': {intelect++; break; }
		case '2': {luck++; break; }
		case '3': {strength++; break; }
		case '4': {stamina++; break; }
		default: {cout << "\nNo such option."; }
		}
		break;
	}
	//Increasing stats
	lvl ++;
	hp = this->getMaxHP();
	mana = this->getMaxMana();
	exp2 = this->getMaxExp();
	armor = 50 + strength;

	//Showing stats, will be removed later
	cout << "Showing stats.";
	cout << "\n1. Intelect: " << intelect << "\n2. Luck:  " << luck << "\n3. Strength: " << strength << "\n4. Stamina:  " << stamina << "\nArmor: " << armor << "\nHP: " << hp <<
		"\nMana: " << mana << "\n";
	getchar(); getchar();
}
void Character::Move() {
	system("cls");
	if (this->energy >= 5) {
		std::cout << "\nWhere do you want to go?\n1. North\n2. East\n3. South\n4. West\n\n5. Exit\n";
		char move;
		cin >> move;
		switch (move) {
		case '1': {
			std::cout << "You went north";
			this->ypos++;
			this->nom++;
			this->energy -= 5;
			appendArrY(arry);
			appendArrXSame(arrx);
			if(wasYouHere(arrx, arry)==true){cout<<"\nYou have been here before"<<endl; }
			Sleep(1000); break;
		}
		case '2': {
			std::cout << "You went east";
			this->xpos++;
			this->nom++;
			this->energy -= 5;
			appendArrX(arrx);
			appendArrYSame(arry);
			if (wasYouHere(arrx, arry) == true) { cout << "\nYou have been here before" << endl; }
			Sleep(1000);
			break;
		}
		case '3': {
			std::cout << "You went south";
			this->ypos--;
			this->nom++;
			this->energy -= 5;
			appendArrY(arry);
			appendArrXSame(arrx);
			if (wasYouHere(arrx, arry) == true) { cout << "\nYou have been here before" << endl; }
			Sleep(1000);
			break;
		}
		case '4': {
			std::cout << "You went west";
			this->xpos--;
			this->nom++;
			this->energy -= 5;
			appendArrX(arrx);
			appendArrYSame(arry);
			if (wasYouHere(arrx, arry) == true) { cout << "\nYou have been here before" << endl; }
			Sleep(1000);
			break;
		}
		case '5': {break; }
		default: {std::cout << "No such option"; Sleep(1000); break; }
		}
	}
	else std::cout << "You don't have energy to travel."; Sleep(1000);
	
}
void Character::Rest() {
	this->hp = this->getMaxHP();
	this->mana = this->getMaxMana();
	this->energy = this->getMaxEnergy();
	cout << "\nYou rest and regain your hp, energy and mana";
	cout << "\nHp: " << this->hp;
	cout << "\nMana: " << this->mana;
	cout << "\nEnergy: " << this->energy;
	Sleep(2000);
}
void Character::CharacterSheet() {
	cout << "Name: " << this->name << endl;
	cout << "Intelect: " << this->intelect << endl;
	cout << "Strength: " << this->strength << endl;
	cout << "Stamina: " << this->stamina << endl;
	cout << "Luck: " << this->luck << endl;
	cout << "Armor: " << this->armor << endl;
	cout << "HP: " << this->hp << endl;
	cout << "Mana: " << this->mana << endl;
	cout << "Energy: " << this->energy << endl;
	cout << "Level: " << this->lvl << endl;
	cout << "Gold: " << this->gold << endl;
	cout << "Experience: " << this->exp << endl;
	cout << "Experience needed to level up: " << this->exp2 << endl;
	cout << "\n Xpos: " << this->xpos;
	cout << "\n Ypos: " << this->ypos;
}
void Character::appendArrX(int* arrx) {
	arrx[this->ax] = this->xpos;
	ax++;
}
void Character::appendArrY(int* arry) {
	arry[this->ay] = this->ypos;
	ay++;
}
void Character::appendArrXSame(int* arrx) {
	arrx[this->ax] = arrx[(this->ax) - 1];
	ax++;
}
void Character::appendArrYSame(int* arry) {
	arry[this->ay] = arry[(this->ay) - 1];
	ay++;
}
void Character::showArr(int* arr,char x, int index) {
	cout << "\nYour recent "<<x<<" coordinates:\n";
	for (int i = 0; i < index; i++) {
		cout << arr[i] << endl;
	}
	getchar(); getchar();
}

int Character::Attack() {
	cout << "\n1. Fireball\n2. Smash\n";
	for (;;) {
		char choice;
		std::cin >> choice;
		switch (choice) {
		case '1': {
			if (this->mana <= 0) {
				cout << "I need more mana";
				return 0;
				break;
			}
			else if (this->mana >= 50) {
				this->mana -= 50;
				return (rand() % (this->intelect) * (this->lvl) + 1);
				break;
			}
		}
		case '2': {
			return (rand() % (this->strength) * (this->lvl) + 1);
			break;
		}
		default: {std::cout << "No such option."; break; }
		}
	}
}
int Character::getMaxHP() {
	this->maxhp = (((this->lvl) - 1) * 10 + 50);
	return maxhp;
}
int Character::getMaxMana() {
	this->maxmana = (((this->lvl) - 1) * 10 * this->intelect + 100);
	return maxmana;
}
int Character::getMaxExp() {
	this->exp2 = (((this->lvl - 1) * 10) + 5);
	return exp2;
}
int Character::getMaxEnergy() {
	return this->stamina * 10;
}
int Character::getLvl() {
	return this->lvl;
}

bool Character::notDead() {
	if (this->hp > 0) {
		return true;
	}
}
bool Character::wasYouHere(int* arrx, int* arry) {
	for (int i=0; i<this->ax; i++) {
		if (arrx[i] == arrx[this->ax] && arry[i] == arry[this->ay]) return true; //Doesn't work well
	}
}
bool Character::isNoMoves100() {
	if (this->nom == 50) return true;
	else return false;
}

Character::Character(string n, int i, int s, int a, int stam, int lev)
{
	lvl = 1; //Level
	intelect = i; strength = s, luck = a, stamina = stam; //Stats
	gold = 0;
	exp = 0;
	exp2 = getMaxExp(); //Exp needed to lvl up
	
	nom = 0;
	xpos = 0;
	ypos = 0;
	
	hp = 50;
	mana = 100;
	armor = 50 + strength;
	int points = 20;
	cout << "You have a dream. \n";
	cout << "What is your name anon? "; cin >> name;
	cout << "You have "<<points<<" points to redistribute. Choose very wisely " << name << " for there will be no return.\n";
	getchar(); getchar();
	
	EnterStats(points, intelect, "Intelect: ");
	EnterStats(points, luck, "Luck: ");
	EnterStats(points, strength, "Strength: ");
	EnterStats(points, stamina, "Stamina: ");

	this->energy = this->stamina * 10;
	this->ax = 1;
	this->ay = 1;
	this->arrx[0] = xpos;
	this->arry[0] = ypos;
}
Character::~Character()
{
}

