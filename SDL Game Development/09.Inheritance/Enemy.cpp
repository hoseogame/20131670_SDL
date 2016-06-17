#include "Enemy.h"
#include "InputHandler.h"

void Enemy::draw()
{
	SDLGameObject::draw();
}
void Enemy::load(const LoaderParams *pParams)
{
	SDLGameObject::load(pParams);
	m_velocity.setY(2);
}
void Enemy::update()
{
	if (m_position.getY() < 0)
	{
		m_velocity.setY(2);
	}
	else if (m_position.getY() > 400)
	{
		m_velocity.setY(-2);
	}
	SDLGameObject::update();

}
void Enemy::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}
void Enemy::clean()
{
}
