#include "Deadline.h"
#include "InputHandler.h"



Deadline::Deadline()
{
}
void Deadline::load(const LoaderParams* pParams)
{
	SDLGameObject::load(pParams);
}
void Deadline::draw()
{
	SDLGameObject::draw();
}
void Deadline::update()
{
	SDLGameObject::update();
}
void Deadline::clean()
{
}
void Deadline::handleInput()
{
	/*if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;*/
}

Deadline::~Deadline()
{
}
