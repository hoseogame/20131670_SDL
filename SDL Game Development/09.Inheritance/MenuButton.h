#ifndef _MENUBUTTON_H_
#define _MENUBUTTON_H_

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

enum button_state { MOUSE_OUT = 0, MOUSE_OVER, CLICKED };

class MenuButton : public SDLGameObject
{
public:
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams *pParams);
	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }

private:
	int m_callbackID;
	void(*m_callback)();
	bool m_bReleased;
};
class MenuButtonCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new MenuButton();
	}
};

#endif _MENUBUTTON_