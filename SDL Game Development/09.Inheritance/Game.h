#ifndef  _GAME_H_
#define  _GAME_H_

#include <SDL.h>
#include <vector>
#include "GameObject.h"
#include "GameStateMachine.h"
#include <SDL_ttf.h>

class Game
{
public :
	static Game* Instance()
	{
		if ( s_pInstance == 0 )
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	~Game();
	bool init( const char* title, int xpos, int ypos, int width, int height, bool fullscreen );
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }
	
private:
	Game();
	static Game* s_pInstance;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;

	int m_currentFrame;
	int m_currentFrame2;

	bool m_bRunning;
 
	std::vector<GameObject*> m_gameObject;
	GameStateMachine* m_pGameStateMachine;

	TTF_Font* m_font;
	SDL_Color textColor;
	
	SDL_Texture* blendedTexture;
	SDL_Rect blendedRect;
};
typedef Game TheGame;

#endif // ! 