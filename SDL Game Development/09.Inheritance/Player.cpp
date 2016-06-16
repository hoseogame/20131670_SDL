#include "Player.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"
#include "Body.h"
#include "SnakeDefine.h"

Player::Player() : SDLGameObject(), m_prevPosition(m_position), m_direction(E_NONE), m_prevDirection(E_NONE)
{
	/*snake_tail = (struct BODY *)malloc(sizeof(struct BODY));
	snake_tail->position.setX(5);
	snake_tail->position.setY(3);
	snake_head = snake_tail;
	snake_head = (struct BODY *)malloc(sizeof(struct BODY));
	snake_head->position.setX(4);
	snake_head->position.setX(3);
	snake_tail->next = NULL;
	snake_head->next = snake_tail;*/

	m_bodys.clear();
	Body* createdBody = reinterpret_cast<Body*>(TheGameObjectFactory::Instance()->create("Body"));
	//createdBody->load(new LoaderParams(0, 0, 55, 55, "Body", 1));
	createdBody->setPosition(m_position + Vector2D(m_width * -1.0f, 0.0f));
	createdBody->setPrevbody(NULL);
	createdBody->setPrevDirection(m_direction);
	m_bodys.push_back(createdBody);


	for (int i = 1; i < 3; ++i) {
		createdBody = reinterpret_cast<Body*>(TheGameObjectFactory::Instance()->create("Body"));
		//createdBody->load(new LoaderParams(0, 0, 55, 55, "Body", 1));
		createdBody->setPosition(m_bodys[i-1]->getPosition() + Vector2D(m_bodys[i - 1]->getWidth() * -1.0f, 0.0f));
		createdBody->setPrevbody(m_bodys[i - 1]);
		m_bodys.push_back(createdBody);
	}
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

	//CollisionSelf();
	//m_velocity.setX(0);
	//m_velocity.setY(0);
	m_prevPosition = m_position;
	m_position += m_velocity;
	handleInput(); // add our function

	m_bodys[0]->setPrevPosition(m_bodys[0]->getPosition());

	switch (m_direction)
	{
	case E_UP:
		m_bodys[0]->setPosition(m_prevPosition + Vector2D(0.0f, m_height));
		break;

	case E_LEFT:
		m_bodys[0]->setPosition(m_prevPosition + Vector2D(m_width, 0.0f));
		break;

	case E_RIGHT:
		m_bodys[0]->setPosition(m_prevPosition + Vector2D(m_width * -1.0f, 0.0f));
		break;

	case E_DOWN:
		m_bodys[0]->setPosition(m_prevPosition + Vector2D(0.0f, m_height * -1.0f));
		break;
	}

	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	

	for (int i = 0; i < m_bodys.size(); ++i)
	{
		m_bodys[i]->update();
	}
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		if (m_direction != E_UP) 
		{
			if (m_direction != E_NONE) {
				m_prevDirection = m_direction;
			}

			m_velocity.setY(-4);
			m_velocity.setX(0);
			m_direction = E_UP;
		}
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		if (m_direction != E_LEFT)
		{
			if (m_direction != E_NONE) {
				m_prevDirection = m_direction;
			}

			m_velocity.setX(-4);
			m_velocity.setY(0);
			m_direction = E_LEFT;
		}
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		if (m_direction != E_RIGHT)
		{
			if (m_direction != E_NONE) {
				m_prevDirection = m_direction;
			}

			m_velocity.setX(4);
			m_velocity.setY(0);
			m_direction = E_RIGHT;
		}
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		if (m_direction != E_DOWN)
		{
			if (m_direction != E_NONE) {
				m_prevDirection = m_direction;
			}

			m_velocity.setY(4);
			m_velocity.setX(0);
			m_direction = E_DOWN;
		}
	}

	//m_velocity = *target - m_position;
	//m_velocity /= 50;
	/*if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
		Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
		m_velocity = (*vec - m_position) / 100;
	}*/
}
void Player::make_tail()
{
	/*
	int tmp_x, tmp_y;
	int i = 0;
	struct BODY *tmp_body;

	tmp_x = snake_head->position.getX();
	tmp_y = snake_head->position.getY();

	switch (direction)
	{
	case 1:
		m_velocity.setY(-1);
		break;
	case 2:
		m_velocity.setX(-1);
		break;
	case 3:
		m_velocity.setX(1);
		break;
	case 4:
		m_velocity.setY(1);
		break;
	}
	tmp_body = (struct BODY *)malloc(sizeof(struct BODY));	//머리부분의 새로운 노드만들기
	tmp_body->position.setX(tmp_x);
	tmp_body->position.setY(tmp_y);
	tmp_body->next = snake_head;
	snake_head = tmp_body;
	*/
}

void Player::clean()
{
}