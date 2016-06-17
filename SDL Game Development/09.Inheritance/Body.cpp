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

		//direction�� ���� ����.
		switch (m_direction)
		{
		case E_UP:
			if (m_spinInfoQueue.size() > 0) //��������Ʈ ť�� ��������Ʈ�� �� ���� ��� 
			{
				if (m_position.getY() <= m_spinInfoQueue.front().m_spinPosition.getY()) //���� ����Ʈ�� ��������Ʈ���� ������ 
				{
					isSpinned = true;
				}
				else //���� ������ velocity ����  
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
			m_prevDirection = m_direction; //������ �𷺼��� ������ �𷺼ǿ� �־���. (�ٲܿ����̶�)
	
			m_direction = m_spinInfoQueue.front().m_afterDirection; //���� �𷺼��� ��������Ʈť�ȿ� �ִ� �ٲ� �𷺼�.
			m_position = m_spinInfoQueue.front().m_spinPosition; // ������ ����.

			switch (m_direction) //�𷺼ǿ� ���� ������
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

			if (m_nextBody != NULL)  //���� �ٵ� ���� �ʴٸ�.
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
