#ifndef _ANIMATEDGRAPHIC_H_
#define _ANIMATEDGRAPHIC_H_

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class AnimatedGraphic : public SDLGameObject
{
public:
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParams);

private :
	int m_animSpeed;
	int m_currentFrame;
	int m_numFrames;
};
class AnimatedGraphicCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new AnimatedGraphic();
	}
};

#endif