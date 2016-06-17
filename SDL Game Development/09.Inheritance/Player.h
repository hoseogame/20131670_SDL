#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "SDLGameObject.h"
#include "GameObjectFactory.h"
#include "SnakeDefine.h"
#include <vector>

class Body;
////�� ���� 
//struct BODY 
//{
//	//sprite�� ������ �־����.
//	Vector2D	position;
//	struct BODY * next;
//};
class Player : public SDLGameObject
{
public:
	Player();
	void draw();
	void update(); 
	void clean();
	void load( const LoaderParams* pParams );
	void make_tail(); // ������ �������

	void setDirection(SNAKE_DIRECTION direction) { m_direction = direction; }
	//bool CollisionSelf(); //����� �Ӹ� �浹üũ ������ 
private :
	void handleInput();
	    
	SNAKE_DIRECTION m_direction;				//���� ���� �Ӹ��� ���ϴ� ����. (����:0, ��:1,����:2,������:3,�Ʒ�:4)
	SNAKE_DIRECTION m_prevDirection;			//���� ���ۿ��� ������ ����	//�ѽ��ۿ��� ������ �ι��ٲܽ� �浹 ������� ����

	int m_tailCount;
	bool m_isSpinned;

	//Vector2D m_prevPosition;
	//Vector2D m_spinPosition;
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

