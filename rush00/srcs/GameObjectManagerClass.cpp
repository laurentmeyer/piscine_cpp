#include "GameObjectManagerClass.hpp"
#include "GameManagerClass.hpp"
#include "PlayerClass.hpp"
#include "EnemyClass.hpp" //
#include <iostream>
#include <unistd.h>

size_t			GameObjectManager::_countGameObjects = 0;
AGameObject 	*GameObjectManager::_gameObjects[] = {nullptr};
size_t const	GameObjectManager::_maxGameObjects = sizeof(GameObjectManager::_gameObjects) / sizeof(GameObjectManager::_gameObjects[0]);
Player 			*GameObjectManager::_player = nullptr;
AGameObject		*GameObjectManager::_gameObjectsToDestroy[] = {nullptr};
size_t			GameObjectManager::_countGameObjectsToDestroy = 0;
float			GameObjectManager::_lastEnemyGenerated = Time::sinceStart();
float const		GameObjectManager::_secondsPerEnemyGeneration = 1.;

void	GameObjectManager::init(void)
{
	GameObjectManager::_player = new Player(5, 7);
	GameObjectManager::addGameObject(GameObjectManager::_player);
}

void	GameObjectManager::destroy(void)
{
	for (size_t i = 0; i < GameObjectManager::_maxGameObjects; i++)
		if (nullptr != GameObjectManager::_gameObjects[i])
		{
			delete GameObjectManager::_gameObjects[i];
			GameObjectManager::_gameObjects[i] = nullptr;
		}
}

void GameObjectManager::addGameObject(AGameObject *a)
{
	if (GameObjectManager::_countGameObjects >= GameObjectManager::_maxGameObjects)
	{
		GameManager::quit("Maximum number of objects reached");
		return;
	}
	for (size_t i = 0; i < GameObjectManager::_maxGameObjects; i++)
		if (nullptr == GameObjectManager::_gameObjects[i])
		{
			GameObjectManager::_gameObjects[i] = a;
			GameObjectManager::_countGameObjects++;
			return;
		}
}

void GameObjectManager::deleteGameObject(AGameObject *a)
{
	GameObjectManager::_gameObjectsToDestroy[GameObjectManager::_countGameObjectsToDestroy++] = a;
}

void GameObjectManager::_destroyOneGameObject(AGameObject *a)
{
	size_t pos = GameObjectManager::_maxGameObjects + 1;
	bool kill_player = (a == GameObjectManager::_player);
	static bool playSound = ( access( "./assets/lose.mp3", F_OK ) != -1 );

	for (size_t i = 0; i < GameObjectManager::_maxGameObjects; i++)
		if (a == GameObjectManager::_gameObjects[i])
		{
			pos = i;
			break;
		}
	if (pos > GameObjectManager::_maxGameObjects)
		return;
	delete a;
	GameObjectManager::_countGameObjects--;
	GameObjectManager::_gameObjects[pos] = nullptr;
	if (kill_player)
	{
		GameManager::quit("You DIED! GAME OVER");
		if (playSound)
			system("afplay ./assets/lose.mp3 -v 0.8&");
	}
}

AGameObject	*GameObjectManager::getPlayer(void)
{
	return GameObjectManager::_player;
}
void GameObjectManager::_destroyGameObjectBuffer(void)
{
	for (size_t i = 0; i < GameObjectManager::_countGameObjectsToDestroy; i++)
		GameObjectManager::_destroyOneGameObject(GameObjectManager::_gameObjectsToDestroy[i]);
	GameObjectManager::_countGameObjectsToDestroy = 0;
}

void GameObjectManager::update(void)
{
	AGameObject *a;
	int const cols = DisplayManager::getCols();
	int const rows = DisplayManager::getRows();
	AGameObject *map[rows * cols];

	GameObjectManager::_generateRandomElements();
	for (int i = 0; i < rows * cols; i++)
		map[i] = nullptr;
	for (size_t i = 0; i < GameObjectManager::_maxGameObjects; i++)
	{
		a = GameObjectManager::_gameObjects[i];
		if (nullptr == a)
			continue;
		a->updatePosition(map);
	}
	GameObjectManager::_destroyGameObjectBuffer();
}

void GameObjectManager::display(void)
{
	AGameObject *a;
	for (size_t i = 0; i < GameObjectManager::_maxGameObjects; i++)
	{
		a = GameObjectManager::_gameObjects[i];
		if (nullptr != a)
			DisplayManager::pixelPut(a->getX(), a->getY(), a->getCurse());
	}
}

void GameObjectManager::_generateRandomElements(void)
{
	float now = Time::sinceStart();
	float timeDiff = now - GameObjectManager::_lastEnemyGenerated;

	if (timeDiff >= GameObjectManager::_secondsPerEnemyGeneration)
	{
		int y = std::rand() % DisplayManager::getRows();
		GameObjectManager::addGameObject(new Enemy(DisplayManager::getCols() - 2, y));
		GameObjectManager::_lastEnemyGenerated = now;
	}
}