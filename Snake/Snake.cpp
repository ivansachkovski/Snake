#include "stdafx.h"

CSnake::CSnake()
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

bool CSnake::Contain(const CPoint& point)
{
	for (auto& pointIter : m_body)
	{
		if (pointIter.Equal(point))
		{
			return true;
		}
	}

	return false;
}