#pragma once

struct CPoint
{
	size_t m_xWidth;
	size_t m_yHeight;

	explicit CPoint(size_t xWidth = 0, size_t yHeight = 0) :
		m_xWidth(xWidth),
		m_yHeight(yHeight)
	{

	}

	bool Equal(size_t xWidth, size_t yHeight)
	{
		return (m_xWidth == xWidth && m_yHeight == yHeight);
	}

	bool Equal(const CPoint& point)
	{
		return Equal(point.m_xWidth, point.m_yHeight);
	}

};

using PointsQueue = std::deque<CPoint>;

class ISnake
{
public:
	virtual size_t GetLength() = 0;
	virtual bool Contain(const CPoint&) = 0;
};


class IField
{
public:
	virtual bool Tic() = 0;
	virtual void Print() = 0;
};