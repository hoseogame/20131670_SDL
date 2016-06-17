#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "AnimateGraphic.h"
#include "MenuButton.h"
#include "GameObject.h"
#include "StateParser.h"
#include "MainMenuState.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}
void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}
bool GameOverState::onEnter()
{
	TheGameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());
	StateParser stateParser ;
	stateParser.parseState("text.xml", s_gameOverID, &m_gameObjects, &m_textureIDList);

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_gameOverToMain);
	m_callbacks.push_back(s_restartPlay);
	setCallbacks(m_callbacks);

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		MenuButton* temp = static_cast<MenuButton*>(m_gameObjects[i]);

		if (temp != nullptr) //직접적으로 선택해서 해줌;
		{
			if (temp->getCallbackID() == 2)
			{
				temp->setCallback(s_gameOverToMain);
			}
			else if (temp->getCallbackID() ==3 )
			{
				temp->setCallback(s_restartPlay);
			}
		}
	}
	return true;
}
void GameOverState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void GameOverState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool GameOverState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("gameovertext");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->clearFromTextureMap("restartbutton");

	return true;
}
void GameOverState::setCallbacks(const std::vector<Callback>& callbacks)
{}


