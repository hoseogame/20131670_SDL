#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "SDLGameObject.h"
#include "GameObjectFactory.h"
#include "SnakeDefine.h"
#include <vector>

class Body;

class Player : public SDLGameObject
{
public:
	Player();
	void draw();
	void update(); 
	void clean();
	void load( const LoaderParams* pParams );
	void make_tail(); // 꼬리를 만들어줌

	void setDirection(SNAKE_DIRECTION direction) { m_direction = direction; }

private :
	void handleInput();
	    
	SNAKE_DIRECTION m_direction;				//현재 뱀의 머리가 향하는 방향. (멈춤:0, 위:1,왼쪽:2,오른쪽:3,아래:4)
	SNAKE_DIRECTION m_prevDirection;			//이전 스템에서 움직인 방향	//한스템에서 방향을 두번바꿀시 충돌 디버깅을 위함

	int m_tailCount;
	bool m_isSpinned;
	Body* next;

	std::vector<Body*> m_bodys;
};

class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Player();
	}
};
#endif // !_PLAYER_H_

