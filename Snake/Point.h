#pragma once

// Use this enumeration for determination of shake's movement direction
enum EDirection
{
	eUp,
	eDown,
	eRight,
	eLeft,
	eUnknown
};


class CPoint
{
private:
	size_t m_xWidth;
	size_t m_yHeight;

public:
	explicit CPoint(size_t xWidth, size_t yHeight) :
		m_xWidth(xWidth),
		m_yHeight(yHeight)
	{

	}

	bool EqualTo(size_t xWidth, size_t yHeight) const
	{
		return (m_xWidth == xWidth && m_yHeight == yHeight);
	}

	bool EqualTo(const CPoint& point) const
	{
		return EqualTo(point.m_xWidth, point.m_yHeight);
	}

	CPoint GetNextPointAccordingToDirection(const EDirection direction) const
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


class ISnake
{
public:
	virtual void Init(const CPoint&) = 0;

	virtual void Tic(const EDirection) = 0;

	virtual bool Contains(const CPoint&) const = 0;

	virtual void Grow() = 0;

	virtual size_t GetLength() const = 0;
	
	virtual CPoint GetHead() const = 0;

};


class IField
{
public:
	virtual bool Tic(const int) = 0;
	
	virtual void PrintToConsole() const = 0;

};