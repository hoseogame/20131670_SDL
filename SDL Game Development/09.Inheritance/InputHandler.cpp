#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;
InputHandler::InputHandler()
{
	m_mousePosition = new Vector2D(0, 0);
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
}

void InputHandler::clean()
{
}
void InputHandler::update()
{
	SDL_Event event;
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->clean();
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
		}
	}
}
void InputHandler::onKeyDown()
{
	m_keystates = SDL_GetKeyboardState(0);
}
void InputHandler::onKeyUp()
{
	m_keystates = SDL_GetKeyboardState(0);
}
void InputHandler::onMouseMove(SDL_Event& evt)
{
	if (evt.type == SDL_MOUSEMOTION)
	{
		m_mousePosition->setX(evt.motion.x);
		m_mousePosition->setY(evt.motion.y);
	}
}
void InputHandler::onMouseButtonDown(SDL_Event& evt)
{
	if (evt.type == SDL_MOUSEBUTTONDOWN)
	{
		if (evt.button.button == SDL_BUTTON_LEFT)
		{
			m_mouseButtonStates[LEFT] = true;
		}
		if (evt.button.button == SDL_BUTTON_MIDDLE)
		{
			m_mouseButtonStates[MIDDLE] = true;
		}
		if (evt.button.button == SDL_BUTTON_RIGHT)
		{
			m_mouseButtonStates[RIGHT] = true;
		}
	}
}
void InputHandler::onMouseButtonUp(SDL_Event& evt)
{
	if (evt.type == SDL_MOUSEBUTTONUP)
	{
		if (evt.button.button == SDL_BUTTON_LEFT)
		{
			m_mouseButtonStates[LEFT] = false;
		}
		if (evt.button.button == SDL_BUTTON_MIDDLE)
		{
			m_mouseButtonStates[MIDDLE] = false;
		}
		if (evt.button.button == SDL_BUTTON_RIGHT)
		{
			m_mouseButtonStates[RIGHT] = false;
		}
	}
}


bool InputHandler::getMouseButtonState(int buttonScore)
{
	return m_mouseButtonStates[buttonScore];
}
Vector2D* InputHandler::getMousePosition()
{
	return m_mousePosition;
}
bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystates != 0) 
	{
		if (m_keystates[key] == 1)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	return false;
}
