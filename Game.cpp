#include "pch.h"
#include "NewGame.h"
#include "Game.h"
#include "Menu.h"
#include <iostream>
#include <Windows.h>

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
		cout << "To jest intro\nWcisnij cos zeby przejsc do menu";
		getchar();
		_gameState = ShowingMenu;
		break;
	}
	case Game::ShowingMenu: {
		system("cls"); //Cleans screen
		Menu::ShowMenu(); //Shows menu

		char choice;  //Choose which option from menu you want
		choice = getchar();
		switch (choice) {
		case '1': _gameState = Playing; break;
		case '2': _gameState = About; break;
		case'3':_gameState = Exiting; break;
		default: printf("No such option"); Sleep(500); break;
		}
	}
	case Game::Playing: {
		NewGame::Play();
		break;
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
