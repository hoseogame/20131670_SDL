#ifndef		_ENEMY_H_
#define		_ENEMY_H_

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Enemy : public SDLGameObject
{
public:
	void load(const LoaderParams *pParams);
	void draw();
	void update();
	void clean();
	void handleInput();
};
class EnemyCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Enemy();
	}
};

#endif

