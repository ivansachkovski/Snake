#pragma once

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

	CPoint GetNextPointAccordingToDirection(const Direction direction) const
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
		default:
			// TODO :: wrong situation
			break;
		}
		
		return CPoint(0, 0);
	}

	bool IsValid() const
	{
		return (m_xWidth != -1) && (m_yHeight != -1);
	}

	void SetInvalid()
	{
		m_xWidth = -1;
		m_yHeight = -1;
	}
};
