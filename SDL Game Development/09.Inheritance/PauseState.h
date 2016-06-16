#ifndef _PAUSESTATE_H_
#define _PAUSESTATE_H_

#include "MenuState.h"

class GameObject;

class PauseState : MenuState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_pauseID; }
	
private:
	static void s_pauseToMain();
	static void s_resumePlay();
	virtual void setCallbacks(const std::vector<Callback>& callbacks);

	static const std::string s_pauseID;
	std::vector<GameObject*> m_gameObjects;
};
#endif
