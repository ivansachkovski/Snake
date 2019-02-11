#include "stdafx.h"

GameController::GameController(GameModel* pModel) :
	m_pModel(pModel)
{

}

void GameController::Start()
{
	std::thread inputThread(&GameController::InputThreadFunction, this);
	m_inputThread = std::move(inputThread);

	ActionsGenerator();
}

void GameController::Stop()
{
	m_stopFlag = true;

	if (m_inputThread.joinable())
	{
		m_inputThread.join();
	}
}

void GameController::ActionsGenerator()
{
	while (!m_stopFlag)
	{
		m_pModel->Move();
	}
}

void GameController::InputThreadFunction()
{
	int inputCharacterCode = 0;
	while (!m_stopFlag)
	{
		m_inputCharacterCode = inputCharacterCode;
		inputCharacterCode = _getch();
	}

	m_stopFlag = true;
}