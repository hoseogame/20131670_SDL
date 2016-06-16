#include "AnimateGraphic.h"
#include "GameObjectFactory.h"

void AnimatedGraphic::load(const LoaderParams* pParams)
{
	SDLGameObject::load(pParams);
	m_animSpeed = pParams->getAnimSpeed();
}

void AnimatedGraphic::update()
{
	if ( m_numFrames != 0  && m_animSpeed != 0 )
		m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
}

void AnimatedGraphic::draw()
{
}
void AnimatedGraphic::clean()
{
}
