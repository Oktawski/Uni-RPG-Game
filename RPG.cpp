#include "pch.h"
#include "Game.h"
#include "NewGame.h"

#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));
	Game::Start();
}

