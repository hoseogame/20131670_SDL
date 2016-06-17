#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject() : GameObject()
{
}
void SDLGameObject::load( const LoaderParams* pParams )
{
	m_position = Vector2D( pParams->getX(), pParams->getY() );
	m_velocity = Vector2D( 0, 0 );
	m_acceleration = Vector2D( 0, 0 );
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 0;
	m_numFrames = pParams->getNumFrames();
}
void SDLGameObject::draw()
{
	if (m_velocity.getX() > 0)
	{
		TheTextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.getX(), (Uint32)m_position.getY(),
			m_width, m_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer(),
			SDL_FLIP_HORIZONTAL);
	}
	else
	{
		if (m_textureID == "Body")
		{
			int i = 0;
		}
		TheTextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.getX(), (Uint32)m_position.getY(),
			m_width, m_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer());
	}
}
void SDLGameObject::DrawPaticial(int _width, int _height,int _currentFrame, int _currentRow)
{
	TheTextureManager::Instance()->drawFrame(m_textureID,
		(Uint32)m_position.getX(), (Uint32)m_position.getY(),
		_width, _height, _currentRow, _currentFrame,
		TheGame::Instance()->getRenderer());
}
void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}
void SDLGameObject::clean()
{
}
