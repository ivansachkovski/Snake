#pragma once

class CSnakeGame :
	public IGame
{
public:
	static constexpr int m_exitCharacterCode = '.';

private:
	std::atomic_bool m_bStop;

	std::atomic_int m_inputCode;

	std::unique_ptr<ISnake> m_pSnake;
	std::unique_ptr<IField> m_pField;

	std::thread m_inputThread;

public:
	CSnakeGame(size_t, size_t);
	void Run() override;

private:
	void InputThreadHandler();
};