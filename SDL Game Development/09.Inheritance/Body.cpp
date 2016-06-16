#include "Body.h"
#include "SnakeDefine.h"


Body::Body() : SDLGameObject(), m_prevBody(NULL), m_prevPosition(m_position)
{
}

void Body::draw()
{
	SDLGameObject::draw();
}
void Body::update()
{
	SDLGameObject::update();

	if (m_prevBody != NULL)
	{
		m_position = m_prevBody->m_prevPosition;
		/*m_prevPosition = m_position;
		m_prevDirection = m_direction;

		switch (next->getDirection())
		{
		case E_UP:
			m_position = next->getPrevPosition() + Vector2D(0.0f, m_height);
			break;

		case E_LEFT:
			m_position = next->getPrevPosition() + Vector2D(m_width, 0.0f);
			break;

		case E_RIGHT:
			m_position = next->getPrevPosition() + Vector2D(m_width * -1.0f, 0.0f);
			break;

		case E_DOWN:
			m_position = next->getPrevPosition() + Vector2D(0.0f, m_height * -1.0f);
			break;
		}
		
		m_direction = next->getDirection();*/
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
