#pragma once

class CGameController :
	public IController
{
private:
	std::atomic_bool m_stopFlag = false;
	std::atomic_int m_inputCharacterCode = 0;

public:
	explicit CGameController(const std::shared_ptr<IModel>& pModel);
	
	void Start();

private:
	void InputThreadFunction();
};