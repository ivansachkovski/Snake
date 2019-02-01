#include "stdafx.h"

CSnake::CSnake():
	m_direction(eRight)
{
	
}

size_t CSnake::GetLength() const
{
	return m_body.size();
}

void CSnake::Tic(const EDirection direction)
{
	ChangeDirection(direction);

	ChangePosition();

	return;
}

void CSnake::ChangeDirection(const EDirection direction)
{
	if (direction != eUnknown)
	{
		switch (m_direction)
		{
		case eUp:
			m_direction = (direction == eDown) ? m_direction : direction;
			break;
		case eDown:
			m_direction = (direction == eUp) ? m_direction : direction;
			break;
		case eLeft:
			m_direction = (direction == eRight) ? m_direction : direction;
			break;
		case eRight:
			m_direction = (direction == eLeft) ? m_direction : direction;
			break;
		default:
			// TODO :: wrong situation 
			break;
		}
	}

	return;
}

void CSnake::ChangePosition()
{
	m_body.push_front(m_body.front().GetNextPointAccordingToDirection(m_direction));
	m_body.pop_back();

	return;
}

void CSnake::Init(const CPoint& point)
{
	m_body.push_back(point);

	return;
}

void CSnake::Grow()
{
	m_body.push_back(m_body.back());

	return;
}

CPoint CSnake::GetHead() const
{
	return m_body.front();
}

bool CSnake::Contains(const CPoint& point) const
{
	for (auto bodyElement : m_body)
	{
		if (bodyElement.EqualTo(point))
		{
			return true;
		}
	}

	return false;
}