#ifndef _Score_H_
#define _Score_H_

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Score : public SDLGameObject
{
public:
	Score();
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	int SumScore();
	~Score();
private :
	int m_score;
};
class ScoreCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Score();
	}
};

#endif

