#pragma once

class GameController
{
protected:
	std::atomic_bool m_stopFlag = false;

	std::thread m_inputThread;

	GameModel* m_pModel;

	std::map<int, std::function<void(void)>> m_commands;

public:
	explicit GameController(GameModel* pModel);
	
	void Start();
	void Stop();

private:
	void InputThreadFunction();

	void ActionsGenerator();

	void HandleCommand(const int commandCode);

};