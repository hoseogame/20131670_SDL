#ifndef  _DEADLINE_H_
#define _DEADLINE_H_

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Deadline : public SDLGameObject
{
public:
	Deadline();
	void draw();
	void update();
	void clean();
	void load(const LoaderParams* pParams);
	void handleInput();
	~Deadline();
};
class DeadlineCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Deadline();
	}
};

#endif // ! _DEADLINE_H_
