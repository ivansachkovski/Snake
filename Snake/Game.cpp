#include "stdafx.h"

void CSnakeGame::Run()
{
	std::thread inputThread(&CSnakeGame::InputThreadHandler, this);
	m_inputThread = std::move(inputThread);

	// Main loop
	while (!m_bStop)
	{
		int actionCode = m_inputCode;

		bool bSuccess = m_pField->Tic(actionCode);

		m_pField->PrintToConsole();

		Sleep(500);
	}

	m_bStop = true;

	if (inputThread.joinable())
	{
		inputThread.join();
	}
};

void CSnakeGame::InputThreadHandler()
{
	int inputCharacterCode = 0;
	while (!m_bStop && inputCharacterCode != m_exitCharacterCode)
	{
		m_inputCode = inputCharacterCode;
		inputCharacterCode = _getch();
	}

	m_bStop = true;

	return;
}