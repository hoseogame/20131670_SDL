#include "Body.h"


Body::Body() : SDLGameObject(), m_prevBody(NULL), m_nextBody(NULL), m_direction(E_NONE), m_prevDirection(E_NONE)//, m_prevPosition(m_position)
{
}

void Body::draw()
{
	SDLGameObject::draw();
}
void Body::update()
{
	SDLGameObject::update();

	//if (m_prevBody != NULL)
	{
		
		//m_prevPosition = m_position;

		bool isSpinned = false;

		//direction에 따라 나뉨.
		switch (m_direction)
		{
		case E_UP:
			if (m_spinInfoQueue.size() > 0) //스핀포인트 큐에 스핀포인트가 들어가 있을 경우 
			{
				if (m_position.getY() <= m_spinInfoQueue.front().m_spinPosition.getY()) //현재 포인트가 스핀포인트보다 작을때 
				{
					isSpinned = true;
				}
				else //작지 않을땐 velocity 변경  
				{
					m_velocity.setX(0);
					m_velocity.setY(-2);
				}
			}
			else 
			{
				m_velocity.setX(0);
				m_velocity.setY(-2);
			}
			break;

		case E_LEFT:
			if (m_spinInfoQueue.size() > 0) 
			{
				if (m_position.getX() <= m_spinInfoQueue.front().m_spinPosition.getX())
				{
					isSpinned = true;
				}
				else {
					m_velocity.setX(-2);
					m_velocity.setY(0);
				}
			}
			else {
				m_velocity.setX(-2);
				m_velocity.setY(0);
			}
			break;

		case E_RIGHT:
			if (m_spinInfoQueue.size() > 0) 
			{
				if (m_position.getX() >= m_spinInfoQueue.front().m_spinPosition.getX())
				{
					isSpinned = true;
				}
				else 
				{
					m_velocity.setX(2);
					m_velocity.setY(0);
				}
			}
			else {
				m_velocity.setX(2);
				m_velocity.setY(0);
			}
			break;

		case E_DOWN:
			if (m_spinInfoQueue.size() > 0) 
			{
				if (m_position.getY() >= m_spinInfoQueue.front().m_spinPosition.getY())
				{
					isSpinned = true;
				}
				else {
					m_velocity.setX(0);
					m_velocity.setY(2);
				}
			}
			else {
				m_velocity.setX(0);
				m_velocity.setY(2);
			}
			break;
		}

		if (isSpinned == true) 
		{
			m_prevDirection = m_direction; //현재의 디렉션을 과거의 디렉션에 넣어줌. (바꿀예정이라)
	
			m_direction = m_spinInfoQueue.front().m_afterDirection; //현재 디렉션은 스핀포인트큐안에 있는 바뀐 디렉션.
			m_position = m_spinInfoQueue.front().m_spinPosition; // 포지션 역시.

			switch (m_direction) //디렉션에 따른 움직임
			{
			case E_UP:
					m_velocity.setX(0);
					m_velocity.setY(-2);
				break;

			case E_LEFT:
					m_velocity.setX(-2);
					m_velocity.setY(0);
				break;

			case E_RIGHT:
					m_velocity.setX(2);
					m_velocity.setY(0);
				break;

			case E_DOWN:
					m_velocity.setX(0);
					m_velocity.setY(2);
				break;
			}

			if (m_nextBody != NULL)  //다음 바디가 없지 않다면.
			{
				m_nextBody->addSpinPosition(m_spinInfoQueue.front()); 
			}
			m_spinInfoQueue.pop();
		}
		m_position += m_velocity;
	}
}
void Body::clean()
{
}
void Body::load(const LoaderParams* pParams)
{
	SDLGameObject::load(pParams);
}

void Body::setPrevbody(Body* prevbody) 
{
	m_prevBody = prevbody;
}
Body::~Body()
{
}
