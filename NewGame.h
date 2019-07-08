#pragma once
#include "Enemy.h"
#include "Character.h"
#include "Game.h"

#include <stdio.h>
#include <string>

class NewGame
{
public:
	static void Play();
	static void Options();
	static void EnemyEncounter(class Character *player, class Enemy *enemy);
	static void EnemyEncounter(class Character* player, class Goblin *enemy);
	static void BasicEncounter(std::string x);
	static void Battle(class Character *player, class Enemy *enemy);
	static void Battle(class Character* player, class Goblin* enemy);
	static void EndGame(class Character *player);
	NewGame();
	~NewGame();
};

