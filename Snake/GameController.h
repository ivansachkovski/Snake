#pragma once

class GameController
{
private:
	std::atomic_bool m_stopFlag = false;
	std::atomic_int m_inputCharacterCode = 0;

	std::thread m_inputThread;

	GameModel* m_pModel;

public:
	explicit GameController(GameModel* pModel);
	
	void Start();
	void Stop();

private:
	void InputThreadFunction();

	void ActionsGenerator();
};