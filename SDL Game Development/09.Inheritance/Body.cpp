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

		switch (m_direction)
		{
		case E_UP:
			if (m_spinInfoQueue.size() > 0) {
				if (m_position.getY() <= m_spinInfoQueue.front().m_spinPosition.getY())
				{
					isSpinned = true;
				}
				else {
					m_velocity.setX(0);
					m_velocity.setY(-2);
				}
			}
			else {
				m_velocity.setX(0);
				m_velocity.setY(-2);
				//m_position = m_prevBody->getPrevPosition() + Vector2D(0.0f, m_height);
			}
			break;

		case E_LEFT:
			//m_position = m_prevBody->getPrevPosition() + Vector2D(m_width, 0.0f);

			if (m_spinInfoQueue.size() > 0) {
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
				//m_position = m_prevBody->getPrevPosition() + Vector2D(0.0f, m_height);
			}
			break;

		case E_RIGHT:
			//m_position = m_prevBody->getPrevPosition() + Vector2D(m_width * -1.0f, 0.0f);

			if (m_spinInfoQueue.size() > 0) {
				if (m_position.getX() >= m_spinInfoQueue.front().m_spinPosition.getX())
				{
					isSpinned = true;
				}
				else {
					m_velocity.setX(2);
					m_velocity.setY(0);
				}
			}
			else {
				m_velocity.setX(2);
				m_velocity.setY(0);
				//m_position = m_prevBody->getPrevPosition() + Vector2D(0.0f, m_height);
			}
			break;

		case E_DOWN:
			//m_position = m_prevBody->getPrevPosition() + Vector2D(0.0f, m_height * -1.0f);

			if (m_spinInfoQueue.size() > 0) {
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
				//m_position = m_prevBody->getPrevPosition() + Vector2D(0.0f, m_height);
			}
			break;
		}

		if (isSpinned) {
			m_prevDirection = m_direction;
			
			//if (m_prevBody != NULL) {
				//m_direction = m_prevBody->getPrevDirection();
			//}
			m_direction = m_spinInfoQueue.front().m_afterDirection;
			m_position = m_spinInfoQueue.front().m_spinPosition;

			switch (m_direction)
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

			//m_position += m_velocity;

			if (m_nextBody != NULL) {
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
