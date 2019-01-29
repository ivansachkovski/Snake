#pragma once

class CPoint
{
	int x;
	int y;
};

using PointsQueue = std::queue<CPoint>;

class CSnake
{
private:
	PointsQueue m_body;

public:
	CSnake();
	~CSnake();

	void EatFood();
};