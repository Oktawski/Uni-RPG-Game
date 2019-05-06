#pragma once
class Game
{
public:
	static void Start();
private:
	static bool IsExiting();	//Is it exiting?
	static void GameLoop();		//Main game
	enum GameState{Uninitialized, ShowingIntro, ShowingMenu, Playing, About, Exiting};	//Game states	
	static GameState _gameState;	//Game state variable
	
	
	Game();
	~Game();
};

