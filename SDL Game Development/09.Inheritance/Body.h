#ifndef  _BODY_H_
#define _BODY_H_

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

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
	Vector2D getPrevPosition() { return m_prevPosition; }
	void setPrevPosition(Vector2D position) { m_position = position; }

	int getPrevDirection() { return m_prevDirection; }
	void setPrevDirection(int prevDirection) { m_prevDirection = prevDirection; }

private :
	Vector2D m_prevPosition;
	Body* m_prevBody;
	int m_prevDirection;
	//Body* next;
};

class BodyCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Body();
	}
};

#endif // ! _BODY_H_