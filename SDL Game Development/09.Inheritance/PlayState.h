#ifndef _PLAYSTATE_H_
#define _PLAYSTATE_H_

#include "GameState.h"
#include "SDLGameObject.h"

class GameObject;
class Player;
class Food;
class Score;
class Body;

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
	virtual std::string getStateID() const { return s_playID; }
	//int getScore() { return m_score; }

private:
	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;
	Player* m_player;
	Food* m_food;
	Score* m_number;
	Body* m_body;
	//Score* m_score;
	//int m_score;
};

#endif _PLAYSTATE_