#include "Score.h"


Score::Score() : m_score(0)
{
}
void Score::load(const LoaderParams* pParams)
{
	SDLGameObject::load(pParams);
}
void Score::draw()
{
	SDLGameObject::DrawPaticial(m_width, m_height, m_score, m_currentRow);
}
int Score::SumScore()
{
	return m_score += 1;
}
void Score::update()
{
	int score = 2;
	SDLGameObject::update();
	m_width = 32;
	m_height = 32;
}
void Score::clean()
{
	SDLGameObject::clean();
}
Score::~Score()
{
}
