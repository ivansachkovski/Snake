#pragma once

class GameController :
	public IController
{
private:
	std::atomic_bool m_stopFlag = false;
	std::atomic_int m_inputCharacterCode = 0;

	std::thread m_inputThread;

public:
	explicit GameController(const std::shared_ptr<IModel>& pModel);
	
	void Start();
	void Stop();

private:
	void InputThreadFunction();

	void ActionsGenerator();
};