#include "Game.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "AnimateGraphic.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Food.h"
#include "Body.h"
#include "Score.h"
#include <string>
#include <iostream>

Game* Game::s_pInstance = 0;

Game::Game()
{
	m_pWindow = 0;
	m_pRenderer = 0;
	m_bRunning = false;
}
Game::~Game()
{
}
bool Game::init( const char* title, int xpos, int ypos, int width, int height, bool fullscreen )
{
	if ( SDL_Init( SDL_INIT_EVERYTHING ) >= 0 )
	{
		// �ʱ�ȭ �����ϸ�, window ����
		m_pWindow = SDL_CreateWindow( title,
			xpos, ypos,
			width, height, fullscreen );

		// window ������ �����ϸ�, renderer ���� 
		if ( m_pWindow != 0 ) {
			m_pRenderer = SDL_CreateRenderer( m_pWindow, -1, 0 );
		}

		SDL_SetRenderDrawColor( m_pRenderer, 25, 125, 255, 255 );    // �� (R,G,B,A) ���� 
	}
	else
	{
		return false; 
	}

	if (!TheTextureManager::Instance()->load("assets/head.png", "Head", m_pRenderer))
	{
		return false;
	}
	if ( !TheTextureManager::Instance()->load("assets/food.png", "Food", m_pRenderer ))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/number.png", "Number", m_pRenderer))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/body.png", "Body", m_pRenderer))
	{
		return false;
	}
	m_pGameStateMachine = new GameStateMachine();

	TheGameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());
	TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
	TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
	TheGameObjectFactory::Instance()->registerType("Food", new FoodCreator());
	TheGameObjectFactory::Instance()->registerType("Body", new BodyCreator());
	TheGameObjectFactory::Instance()->registerType("Number", new ScoreCreator());

	m_bRunning	= true;
	m_pGameStateMachine->pushState(new PlayState);

	return true; // sdl initialize
}

void Game::render()
{
	SDL_RenderClear( m_pRenderer );  
	m_pGameStateMachine->render();
	SDL_RenderPresent( m_pRenderer );   // ������ ���̱�
}

void Game::clean()
{
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow( m_pWindow );
	SDL_DestroyRenderer( m_pRenderer );
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}

void Game::update()
{
	m_pGameStateMachine->update();
}