#include "Player.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"
#include "Body.h"

Player::Player() : SDLGameObject(), m_direction(E_NONE), m_prevDirection(E_NONE), m_tailCount(0), m_isSpinned(false)//, m_prevPosition(m_position)
{
	m_bodys.clear();
}

void Player::load( const LoaderParams* pParams )
{
	SDLGameObject::load( pParams );
}

void Player::draw()
{
	SDLGameObject::draw();

	for (int i = 0; i < m_bodys.size(); ++i)
	{
		m_bodys[i]->draw();
	}
}

void Player::update()
{
	SDLGameObject::update();

	m_isSpinned = false;
	handleInput(); // add our function

	switch (m_direction)
	{
	case E_UP :
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
	m_position += m_velocity;
	
	if (m_bodys.size() > 0) 
	{
		if (m_isSpinned == true) // ��������Ʈ�� true�� �Ǹ� ����Ʈ�� ����  
		{
			m_bodys[0]->addSpinPosition(m_position, m_direction);
		}
		for (int i = 0; i < m_bodys.size(); ++i) //�ٵ�� ���� ����
		{
			m_bodys[i]->update();
		}
	}
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		if ((m_direction != E_UP) && (m_direction != E_DOWN)) 
		{
			if (m_direction != E_NONE) 
			{
				m_prevDirection = m_direction; //���ϴ� ������ none�� �ƴϸ� �𷺼� ����
			}
			else 
			{
				m_prevDirection = E_UP; // ���ϴ� ������ none�̸� ���� �𷺼��� up����. up->up���� �����״�.
			}
			m_direction = E_UP;
			m_isSpinned = true;
		}
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		if ((m_direction != E_LEFT) && (m_direction != E_RIGHT))
		{
			if (m_direction != E_NONE) 
			{
				m_prevDirection = m_direction;
			}
			else 
			{
				m_prevDirection = E_LEFT;
			}

			m_direction = E_LEFT;
			m_isSpinned = true;
		}
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		if ((m_direction != E_LEFT) && (m_direction != E_RIGHT))
		{
			if (m_direction != E_NONE) 
			{
				m_prevDirection = m_direction;
			}
			else 
			{
				m_prevDirection = E_RIGHT;
			}

			m_direction = E_RIGHT;
			m_isSpinned = true;
		}
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		if ((m_direction != E_UP) && (m_direction != E_DOWN))
		{
			if (m_direction != E_NONE) 
			{
				m_prevDirection = m_direction;
			}
			else 
			{
				m_prevDirection = E_DOWN;
			}

			m_direction = E_DOWN;
			m_isSpinned = true;
		}
	}
}
void Player::make_tail()
{
	Body* createdBody = reinterpret_cast<Body*>(TheGameObjectFactory::Instance()->create("Body"));
	
	if (m_bodys.size() <= 0) //�ٵ� �ϳ��� ���ٸ�.
	{
		createdBody->load(new LoaderParams(0, 0, 55, 55, "Body", 1));

		switch (m_direction)
		{
		case E_UP:
			createdBody->setPosition(m_position + Vector2D(0.0f, m_height));
			break;

		case E_LEFT:
			createdBody->setPosition(m_position + Vector2D(m_width, 0.0f));
			break;

		case E_RIGHT:
			createdBody->setPosition(m_position + Vector2D(m_width * -1.0f, 0.0f));
			break;

		case E_DOWN:
			createdBody->setPosition(m_position + Vector2D(0.0f, m_height * -1.0f));
			break;
		}
		createdBody->setPrevbody(NULL); //ù��° �ٵ���. 
		createdBody->setDirection(m_direction); 
		m_bodys.push_back(createdBody); // ���� �ٵ� ���Ϳ� ����.
	}
	else 
	{
		createdBody->load(new LoaderParams(0, 0, 55, 55, "Body", 1));
		switch (m_bodys[m_tailCount-1]->getDirection()) //���� �𷺼��� ������
		{
		case E_UP:
			createdBody->setPosition(m_bodys[m_tailCount - 1]->getPosition() + Vector2D(0.0f, m_bodys[m_tailCount - 1]->getHeight()));
			break;

		case E_LEFT:
			createdBody->setPosition(m_bodys[m_tailCount - 1]->getPosition() + Vector2D(m_bodys[m_tailCount - 1]->getWidth(), 0.0f));
			break;

		case E_RIGHT:
			createdBody->setPosition(m_bodys[m_tailCount - 1]->getPosition() + Vector2D(m_bodys[m_tailCount - 1]->getWidth() * -1.0f, 0.0f));
			break;

		case E_DOWN:
			createdBody->setPosition(m_bodys[m_tailCount - 1]->getPosition() + Vector2D(0.0f, m_bodys[m_tailCount - 1]->getHeight() * -1.0f));
			break;
		}
		createdBody->setPrevbody(m_bodys[m_tailCount - 1]);
		m_bodys[m_tailCount - 1]->setNextBody(createdBody);
		createdBody->setDirection(m_bodys[m_tailCount - 1]->getDirection());
		m_bodys.push_back(createdBody);
	}

	++m_tailCount;
}

void Player::clean()
{
}