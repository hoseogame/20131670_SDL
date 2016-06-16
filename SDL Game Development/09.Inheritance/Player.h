#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "SDLGameObject.h"
#include "GameObjectFactory.h"
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
	//bool CollisionSelf(); //����� �Ӹ� �浹üũ ������ 
private :
	void handleInput();
	    
	int m_direction;				//���� ���� �Ӹ��� ���ϴ� ����. (����:0, ��:1,����:2,������:3,�Ʒ�:4)
	int m_prevDirection;			//���� ���ۿ��� ������ ����	//�ѽ��ۿ��� ������ �ι��ٲܽ� �浹 ������� ����

	Vector2D m_prevPosition;
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

