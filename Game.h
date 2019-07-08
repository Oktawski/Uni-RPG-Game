#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

class Game
{
public:
	friend class NewGame;
	
	static void Start();
	static void GameLoop();		//Main game
	static bool IsExiting();	//Is it exiting?
	enum GameState{Uninitialized, ShowingIntro, ShowingMenu, Playing, About, Exiting, ShowingInventory};	//Game states	
	static GameState _gameState;	//Game state variable
	Game();
	~Game();
};

