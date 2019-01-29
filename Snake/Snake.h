#pragma once

class CSnake : 
	public ISnake
{
private:
	PointsQueue m_body;

public:
	CSnake();
	~CSnake();

	bool Contain(const CPoint&) override;

	void EatFood();
	size_t GetLength() override;
};