#ifndef _MENUSTATE_H_
#define _MENUSTATE_H_

#include"GameState.h"

class GameObject;

class MenuState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }

protected:
	typedef void(*Callback)();
	virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;
	std::vector<Callback> m_callbacks;

private:
	static void s_menuToPlay();
	static void s_exitFromMenu();
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
};

#endif _MENUSTATE_
