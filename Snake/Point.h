#pragma once

class Point
{
private:
	size_t m_xWidth;
	size_t m_yHeight;

public:
	explicit Point(size_t xWidth = -1, size_t yHeight = -1) :
		m_xWidth(xWidth),
		m_yHeight(yHeight)
	{

	}

	bool EqualTo(size_t xWidth, size_t yHeight) const
	{
		return (m_xWidth == xWidth && m_yHeight == yHeight);
	}

	bool EqualTo(Point point) const
	{
		return EqualTo(point.m_xWidth, point.m_yHeight);
	}

	Point GetNextPointAccordingToDirection(Direction direction) const
	{
		switch (direction)
		{
		case eUp:
			return Point(m_xWidth, m_yHeight - 1);
		case eDown:
			return Point(m_xWidth, m_yHeight + 1);
		case eRight:
			return Point(m_xWidth + 1, m_yHeight);
		case eLeft:
			return Point(m_xWidth - 1, m_yHeight);
		default:
			break;
		}

		assert(false);

		return Point(-1, -1);
	}

	bool IsValid() const
	{
		return (m_xWidth != -1) && (m_yHeight != -1);
	}

	bool IsValid(size_t tableHeight, size_t tableWidth) const
	{
		return (m_xWidth < tableWidth) && (m_yHeight < tableHeight);
	}

	void SetInvalid()
	{
		m_xWidth = -1;
		m_yHeight = -1;
	}

	size_t GetX() const
	{
		return m_xWidth;
	}

	size_t GetY() const
	{
		return m_yHeight;
	}
};
