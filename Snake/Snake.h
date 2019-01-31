#pragma once

class CSnake : 
	public ISnake
{
private:
	PointsQueue m_body;

	EDirection m_direction;

public:
	CSnake();
	~CSnake();

	bool Contain(const CPoint&) override;

	void EatFood();
	size_t GetLength() override;

	void Tic(const EDirection) override;

	void Init(const CPoint&) override;

private:

};