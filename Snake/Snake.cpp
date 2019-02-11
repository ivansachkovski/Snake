#include "stdafx.h"

Snake::Snake():
	m_direction(eRight)
{
	
}

size_t Snake::GetLength() const
{
	return m_body.size();
}

bool Snake::Tic(const Direction direction, CPoint& foodCell)
{
	ChangeDirection(direction);

	ChangePosition();

	CheckForGrowth(foodCell);

	return true;
}

void Snake::CheckForGrowth(CPoint& foodCell)
{
	if (GetHead().EqualTo(foodCell))
	{
		Grow();

		foodCell.SetInvalid();
	}

	return;
}

void Snake::ChangeDirection(const Direction direction)
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

void Snake::ChangePosition()
{
	m_body.push_front(m_body.front().GetNextPointAccordingToDirection(m_direction));
	m_body.pop_back();

	return;
}

void Snake::Init(const CPoint& point)
{
	m_body.push_back(point);

	return;
}

void Snake::Grow()
{
	m_body.push_back(m_body.back());

	return;
}

CPoint Snake::GetHead() const
{
	return m_body.front();
}

bool Snake::Contains(const CPoint& point, bool bCheckAsHead) const
{
	// TODO handle bSkipHead parameter
	CPoint head = m_body.front();

	int elementsCounter = 0;

	for (auto bodyElement : m_body)
	{
		if (bodyElement.EqualTo(point))
		{
			return true;
		}

		++elementsCounter;
	}

	return false;
}