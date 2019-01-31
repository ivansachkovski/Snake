#pragma once

enum EDirection
{
	eUp,
	eDown,
	eRight,
	eLeft,
	eUnknown
};

struct CPoint
{
	size_t m_xWidth;
	size_t m_yHeight;

	explicit CPoint(size_t xWidth, size_t yHeight) :
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

	CPoint GetNextPoint(const EDirection direction)
	{
		switch (direction)
		{
		case eUp:
			return CPoint(m_xWidth, m_yHeight - 1);
		case eDown:
			return CPoint(m_xWidth, m_yHeight + 1);
		case eRight:
			return CPoint(m_xWidth + 1, m_yHeight);
		case eLeft:
			return CPoint(m_xWidth - 1, m_yHeight);
		}
	}

};

using PointsQueue = std::deque<CPoint>;

class ISnake
{
public:
	virtual size_t GetLength() = 0;
	virtual bool Contain(const CPoint&) = 0;
	virtual void Tic(const EDirection) = 0;
	virtual void Init(const CPoint&) = 0;
};


class IField
{
public:
	virtual bool Tic(int action) = 0;
	virtual void PrintToConsole() = 0;
};