#include "pch.h"
#include "Game.h"
#include "NewGame.h"

using namespace std;

void Game::Start() {
	if (_gameState != Uninitialized) return;
	_gameState = ShowingIntro;
	while (!IsExiting()) {
		GameLoop();
	}

}
bool Game::IsExiting() {
	if (_gameState == Exiting) return true;
	else return false;
}
void Game::GameLoop() {

	switch (_gameState) {
	case Game::ShowingIntro: {
		cout << "This is intro\nPress a key to go to menu\n";
		getchar();
		_gameState = ShowingMenu;
		break;
	}
	case Game::Playing: {
		NewGame::Play();
		_gameState = ShowingMenu;
		break;
	}
	case Game::About: {
		printf("This game is my final project for a University course");
		getchar(); getchar();
		_gameState = ShowingMenu;
		break;
	}
	case Game::Exiting: {
		exit(0);
	}
	case Game::ShowingMenu: {
		system("cls"); //Cleans screen
		printf("\n1. New game\n2. About\n3. Exit\n"); //Shows menu

		char choice;  //Choose which option from menu you want
		choice = getchar();
		switch (choice) {
		case '1': _gameState = Playing; break;
		case '2': _gameState = About; break;
		case'3':_gameState = Exiting; break;
		default: printf("No such option"); Sleep(500); break;
		}
	}
	}
	
}

Game::GameState Game::_gameState = Game::Uninitialized;

Game::Game() 
{
}
Game::~Game()
{
}
