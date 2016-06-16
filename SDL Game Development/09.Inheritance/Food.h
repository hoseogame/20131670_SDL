#ifndef _FOOD_H_
#define _FOOD_H_

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Food : public SDLGameObject
{
public:
	Food();
	void draw();
	void update();
	void clean();
	void load(const LoaderParams* pParams);
	~Food();
};
class FoodCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Food();
	}
};

#endif