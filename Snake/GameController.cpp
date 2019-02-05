#include "stdafx.h"

CGameController::CGameController(const std::shared_ptr<IModel>& pModel) :
	IController(pModel)
{

}

void CGameController::Start()
{

}

void CGameController::InputThreadFunction()
{
	int inputCharacterCode = 0;
	while (!m_stopFlag)
	{
		m_inputCharacterCode = inputCharacterCode;
		inputCharacterCode = _getch();
	}

	m_stopFlag = true;
}