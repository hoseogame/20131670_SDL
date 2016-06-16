#ifndef  _INPUTHANDLER_H_
#define  _INPUTHANDLER_H_

#include "SDL.h"
#include "Vector2D.h"
#include <vector>

enum mouse_buttons { LEFT = 0, MIDDLE, RIGHT };

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();
	//mouse
	void onMouseMove(SDL_Event& evt);
	void onMouseButtonDown(SDL_Event& evt);
	void onMouseButtonUp(SDL_Event& evt);
	//key
	void onKeyDown();
	void onKeyUp();

	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
	const Uint8* m_keystates;
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;
};
typedef InputHandler TheInputHandler;

#endif // ! _INPUTHANDLER_