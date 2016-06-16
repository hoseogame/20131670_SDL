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
#include "Deadline.h"
#include "Body.h"
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
		// 초기화 성공하면, window 생성
		m_pWindow = SDL_CreateWindow( title,
			xpos, ypos,
			width, height, fullscreen );

		// window 생성을 성공하면, renderer 생성 
		if ( m_pWindow != 0 ) {
			m_pRenderer = SDL_CreateRenderer( m_pWindow, -1, 0 );
		}

		SDL_SetRenderDrawColor( m_pRenderer, 25, 125, 255, 255 );    // 색 (R,G,B,A) 지정 
	}
	else
	{
		return false; // sdl could not initialize
	}

	if (!TheTextureManager::Instance()->load("assets/head.png", "Head", m_pRenderer))
	{
		return false;
	}
	//helicopter2
	if ( !TheTextureManager::Instance()->load("assets/food.png", "Food", m_pRenderer ))
	{
		return false;
	}
	
	if (!TheTextureManager::Instance()->load("assets/back.png", "Deadline", m_pRenderer))
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
	TheGameObjectFactory::Instance()->registerType("Deadline", new DeadlineCreator());
	//푸드
	//TheGameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
	
	TTF_Init();
	m_bRunning	= true;
	m_pGameStateMachine->pushState(new PlayState);

	
	return true; // sdl initialize
}

void Game::render()
{
	SDL_RenderClear( m_pRenderer );  
	m_pGameStateMachine->render();
	SDL_RenderPresent( m_pRenderer );   // 윈도우 보이기
	
	SDL_Surface *screen = NULL;
	SDL_Surface *message = NULL;

	TTF_Font *font;
	SDL_Color color = { 255, 255, 255 };
	font = TTF_OpenFont("HANNA_ttf.ttf", 28);

	message = TTF_RenderText_Solid(font, "blah blah blah", color);

	SDL_BlitSurface(message, NULL, screen, NULL);
	SDL_UpdateWindowSurface(m_pWindow);
}

void Game::clean()
{
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow( m_pWindow );
	SDL_DestroyRenderer( m_pRenderer );
	TTF_Quit();
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