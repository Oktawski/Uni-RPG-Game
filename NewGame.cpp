#include "pch.h"
#include "NewGame.h"
#include "Game.h"

using namespace std;

void NewGame::Play() {
	Character player;
	do {
		system("cls");
		Options();
		char temp = getchar();
		switch (temp) {
		case '1': {
			player.Move();
			if (player.isNoMoves100() == true) {
				cout << "\nYou were walking so much that the World has turned into huge black hole and sucked you into the other dimension\n";
				getchar(); getchar();
				Game::_gameState = Game::ShowingMenu;
				delete[] player.arrx;
				delete[] player.arry;
				break;
			}
			int temp;
			temp = rand() % 10;
			if (temp > 5) {
				Enemy enemy;
				EnemyEncounter(&player, &enemy);
			}
			break;
		}
		case '2': {
			player.showArr(player.arrx, 'x', player.ax);
			player.showArr(player.arry, 'y', player.ay);
			break;
		}
		case '3': {
			player.Rest();
			break;
		}
		case '4': {
			player.CharacterSheet();
			getchar(); getchar();
			break;
		}
		case '5': {
			delete[] player.arrx;
			delete[] player.arry;
			Game::_gameState = Game::ShowingMenu;
			break;
		}
		default: {cout << "\nNo such option\n"; }
		}
	} while (Game::_gameState==Game::Playing && player.hp>0);
}
void NewGame::Options() {
	cout << "\n1. Travel (Energy - 5)";
	cout << "\n2. Show your past coordinates";
	cout << "\n3. Rest";
	cout << "\n4. Character sheet";
	cout << "\n\n5. Exit\n";
}
void NewGame::Battle(class Character *player, class Enemy *enemy) {
	while (true) {
		system("cls");
		std::cout << player->name << "\t\t\t" << enemy->name << "\nHP: " << player->hp << "\t\t\tHP: "
			<< enemy->hp <<"\nMana: " << player->mana << "\n\n";
			enemy->hp -= player->Attack();
			player->hp -= enemy->Attack();

		if (player->hp <= 0) { 
			std::cout << "You died."; 
			Sleep(2000); 
			break; 
		}
		if (enemy->hp <= 0) {
			enemy->hp = 0;
			std::cout << "You killed " << enemy->name;
			player->gold += enemy->getGold();
			player->exp += enemy->exp;
			Sleep(2000);
			if ((player->exp) >= (player->exp2)*(player->lvl)) {
				player->LevelUp();
			}
			break;
		}
		
	}
}
void NewGame::EnemyEncounter(class Character *player, class Enemy *enemy) {
	system("cls");
	std::cout << "\nYou encountered " << enemy->name << ". What do you want to do?\n1. Attack\n2. Run away\n";
	for (;;) {
		char x = getchar();
		if (x == '1') {
			NewGame::Battle(player, enemy);
			break;
		}
		else if (x == '2') {
			std::cout << "\nI'm running away (Energy - 10)";
			player->energy -= 10;
			Sleep(2000);
			break;
		}
		else { std::cout << "\nNo such option\n"; }
	}
}
void NewGame::BasicEncounter(std::string x) {
	std::cout << "\nYou encountered " << x << "\n";
}
NewGame::NewGame()
{
}
NewGame::~NewGame()
{
}
