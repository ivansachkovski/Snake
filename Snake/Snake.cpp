#include "stdafx.h"

CSnake::CSnake():
	m_direction(eRight)
{
	
}

CSnake::~CSnake()
{

}

void CSnake::EatFood()
{

}

size_t CSnake::GetLength()
{
	return m_body.size();
}

void CSnake::Tic(const EDirection direction)
{
	m_direction = (direction == eUnknown) ? m_direction : direction;
	
	m_body.push_front(m_body.front().GetNextPoint(m_direction));
	m_body.pop_back();

	return;
}

void CSnake::Init(const CPoint& point)
{
	m_body.push_back(point);

	return;
}

bool CSnake::Contain(const CPoint& point)
{
	for (auto& bodyElement : m_body)
	{
		if (bodyElement.Equal(point))
		{
			return true;
		}
	}

	return false;
}