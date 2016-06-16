#ifndef _PLAYSTATE_H_
#define _PLAYSTATE_H_

#include "GameState.h"
#include "SDLGameObject.h"

class GameObject;
class Player;
class Food;

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
	virtual std::string getStateID() const { return s_playID; }
	int getScore() { return score; }

private:
	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;
	Player* m_player;
	Food* m_food;
	int score;
};

#endif _PLAYSTATE_