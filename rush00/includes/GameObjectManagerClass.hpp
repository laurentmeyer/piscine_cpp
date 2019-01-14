#ifndef GameObjectManagerClass_HPP
# define GameObjectManagerClass_HPP

# include <iostream>
# include "AGameObjectClass.hpp"
# include "DisplayManagerClass.hpp"
# include "PlayerClass.hpp"

class GameObjectManager {

public: 
	static void		init(void);
	static void		update(void);
	static void		display(void);
	static void		addGameObject(AGameObject *a);
	static void		deleteGameObject(AGameObject *a);
	static void		destroy(void);
	static AGameObject	*getPlayer(void);



private:
	GameObjectManager(void); 
	~GameObjectManager(void); 
	GameObjectManager(GameObjectManager const & src); 
	GameObjectManager &		operator=(GameObjectManager const & rhs);

	static void					_destroyOneGameObject(AGameObject *a);
	static void					_destroyGameObjectBuffer(void);
	static void					_generateRandomElements(void);

	static Player 				*_player;
	static size_t const			_maxGameObjects;
	static size_t				_countGameObjects;
	static AGameObject			*_gameObjects[512];
	static AGameObject			*_gameObjectsToDestroy[512];
	static size_t				_countGameObjectsToDestroy;
	static float				_lastEnemyGenerated;
	static float const			_secondsPerEnemyGeneration;


};

#endif