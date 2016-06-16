#include "Food.h"


Food::Food() : SDLGameObject()
{
}
void Food::load(const LoaderParams* pParams)
{
	SDLGameObject::load(pParams);
	//m_velocity.setY(2);
}
void Food::draw()
{
	SDLGameObject::draw();
}
void Food::update()
{
	//m_velocity.setX(2);
	//m_velocity.setY(2);
	SDLGameObject::update();
}

void Food::clean()
{
}


Food::~Food()
{
}
