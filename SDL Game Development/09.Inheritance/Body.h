#ifndef  _BODY_H_
#define _BODY_H_

#include "SDLGameObject.h"
#include "GameObjectFactory.h"
#include "SnakeDefine.h"
#include <queue>

struct SpinInfo {
	Vector2D m_spinPosition;
	SNAKE_DIRECTION m_afterDirection;

	SpinInfo(Vector2D spinPosition, SNAKE_DIRECTION direction) {
		m_spinPosition = spinPosition;
		m_afterDirection = direction;
	}
};

class Body : public SDLGameObject
{
public:
	Body();
	void draw();
	void update();
	void clean();
	void load(const LoaderParams* pParams);
	~Body();

	void setPrevbody(Body* prevbody);

	void setNextBody(Body* nextBody) { m_nextBody = nextBody; }
	Body* getNextBody() { return m_nextBody; }

	//Vector2D getPrevPosition() { return m_prevPosition; }
	//void setPrevPosition(Vector2D prevPosition) { m_prevPosition = prevPosition; }

	SNAKE_DIRECTION getPrevDirection() { return m_prevDirection; }
	void setPrevDirection(SNAKE_DIRECTION prevDirection) { m_prevDirection = prevDirection; }

	SNAKE_DIRECTION getDirection() { return m_direction; }
	void setDirection(SNAKE_DIRECTION direction) { m_direction = direction; }

	void addSpinPosition(Vector2D spinPosition, SNAKE_DIRECTION direction) { m_spinInfoQueue.push(SpinInfo(spinPosition, direction)); }
	void addSpinPosition(SpinInfo spinInfo) { m_spinInfoQueue.push(spinInfo); }

private :
	//Vector2D m_prevPosition;
	Body* m_prevBody;
	Body* m_nextBody;
	SNAKE_DIRECTION m_direction;
	SNAKE_DIRECTION m_prevDirection;
	std::queue<SpinInfo> m_spinInfoQueue;
};

class BodyCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Body();
	}
};

#endif // ! _BODY_H_