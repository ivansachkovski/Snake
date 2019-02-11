#include "stdafx.h"

bool Snake::Tic(Point& foodCell)
{
	MoveForward();

	CheckForGrowth(foodCell);

	return true;
}

void Snake::CheckForGrowth(Point& targetCell)
{
	if (front().EqualTo(targetCell))
	{
		GrowUp();

		targetCell.SetInvalid();
	}

	return;
}

void Snake::TryToRotate(const Direction direction)
{
	std::lock_guard<std::mutex> guard(m_mutex);

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
		assert(false);
		break;
	}
}

void Snake::MoveForward()
{
	std::lock_guard<std::mutex> guard(m_mutex);

	push_front(front().GetNextPointAccordingToDirection(m_direction));
	pop_back();
}

void Snake::Init(const Point& point)
{
	clear();

	push_back(point);
}

void Snake::GrowUp()
{
	if (size())
	{
		push_back(back());
	}
	else
	{
		assert(false);
	}
}

bool Snake::Contains(const Point& point, bool bCheckAsHead) const
{
	// TODO handle bSkipHead parameter
	Point head = front();

	int elementsCounter = 0;

	for (auto bodyElement : (*this))
	{
		if (bodyElement.EqualTo(point))
		{
			return true;
		}

		++elementsCounter;
	}

	return false;
}
