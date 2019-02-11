#include "stdafx.h"

GameController::GameController(GameModel* pModel) :
	m_pModel(pModel)
{
	m_commands[72] = [&]() { this->m_pModel->ChangeDirectionTo(eUp); };
	m_commands[80] = [&]() { this->m_pModel->ChangeDirectionTo(eDown); };
	m_commands[77] = [&]() { this->m_pModel->ChangeDirectionTo(eRight); };
	m_commands[75] = [&]() { this->m_pModel->ChangeDirectionTo(eLeft); };
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
		try
		{
			m_pModel->Tic();
			
			Sleep(200);
		}
		catch (const Exception& ex)
		{
			m_stopFlag = true;
		}
	}
}

void GameController::InputThreadFunction()
{
	int inputCommandCode = 0;

	while (!m_stopFlag)
	{
		inputCommandCode = _getch();

		HandleCommand(inputCommandCode);
	}
}

void GameController::HandleCommand(const int commandCode)
{
	auto commandIter = m_commands.find(commandCode);

	if (commandIter != m_commands.end())
	{
		commandIter->second();
	}
}