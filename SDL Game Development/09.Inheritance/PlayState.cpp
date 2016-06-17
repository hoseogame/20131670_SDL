#include "PlayState.h"
#include "GameObject.h"
#include "Game.h"
#include "Player.h"
#include "Food.h"
#include "PauseState.h"
#include "InputHandler.h"
#include "GameOverState.h"
#include "StateParser.h"
#include "Score.h"
#include "SnakeDefine.h"
#include "Body.h"
#include <iostream>
#include <conio.h>

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState((GameState*) new PauseState());
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1]))) // 사과를 먹으면
	{
		m_number->DrawPaticial(m_number->getWidth(), m_number->getHeight(), m_number->SumScore(), 1);
		m_player->make_tail();
		m_food->getPosition() = Vector2D(rand() % 600, rand() % 440);
	}

	if (m_player->getPosition().getX() >= 600.0f || m_player->getPosition().getX() <= 0.0f ||  //게임오버 조건
		m_player->getPosition().getY() >= 440.0f || m_player->getPosition().getY() <= 0.0f )
	{
		TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool PlayState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("text.xml", s_playID, &m_gameObjects, &m_textureIDList);
	
	m_player = dynamic_cast<Player*>(m_gameObjects[0]); //플레이어의 make tail로 접근하기 위한 다운 캐스팅.
	m_player->setDirection(E_RIGHT); //처음 시작은 right 방향으로.
	m_food = dynamic_cast<Food*>(m_gameObjects[1]);
	m_number = dynamic_cast<Score*>(m_gameObjects[2]);

	for (int i = 0; i < 3; ++i) // 테일은 기본적으로 3개로 시작
	{
		m_player->make_tail();
	}
	return true;
}
bool PlayState::onExit()
{
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	return true;
}
bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}