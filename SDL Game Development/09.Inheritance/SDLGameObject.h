#ifndef _SDLGAMEOBJECT_H_
#define _SDLGAMEOBJECT_H_

#include "GameObject.h"
#include "Vector2D.h"


class SDLGameObject : public GameObject
{
public:
	SDLGameObject();
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load( const LoaderParams* pParams );
	virtual void DrawPaticial(int _width, int _height, int _currentFrame, int _currentRow = 1);

	void setPosition(Vector2D position) { m_position = position; }
	Vector2D& getPosition() { return m_position; }

	void setWidth(int width) { m_width = width; }
	void setHeight(int height) { m_height = height; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }

protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	int m_numFrames;
	std::string m_textureID;
};
#endif
