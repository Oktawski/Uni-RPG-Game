#include "pch.h"
#include <iostream>
#include "Game.h"
#include "NewGame.h"
#include <ctime>
int main()
{
	srand(time(NULL));
	Game::Start();
}

