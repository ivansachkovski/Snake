#include "stdafx.h"

SnakeHandler::SnakeHandler(std::unique_ptr<Snake>&& pSnake, size_t width, size_t height) :
	m_width(width),
	m_height(height),
	m_pSnake(std::move(pSnake)),
	m_foodCell(2, 2)
{
	m_pSnake->Init(CPoint(1, 1));
}


bool SnakeHandler::Tic(const int actionCode)
{
	Direction direction = eUnknown;
	direction = ConvertActionToDirection(actionCode);
	
	bool bSuccess = m_pSnake->Tic(direction, m_foodCell);

	if (!m_foodCell.IsValid())
	{
		GenerateNextFoodItem();
	}

	return bSuccess;
}

Direction SnakeHandler::ConvertActionToDirection(const int actionCode) const
{
	Direction direction;

	switch (actionCode)
	{
	case 72:
		direction = eUp;
		break;
	case 80:
		direction = eDown;
		break;
	case 77:
		direction = eRight;
		break;
	case 75:
		direction = eLeft;
		break;
	default:
		direction = eUnknown;
		break;
	}

	return direction;
}


void SnakeHandler::GenerateNextFoodItem()
{
	int freeCellsAmount = (m_height * m_width) - m_pSnake->GetLength();
	
	size_t nextFoodCellIndex = (rand() % freeCellsAmount) + 1;
	
	for (size_t yHeight = 1; yHeight <= m_height; ++yHeight)
	{
		for (size_t xWidth = 1; xWidth <= m_width; ++xWidth)
		{
			if (!m_pSnake->Contains(CPoint(xWidth, yHeight), false))
			{
				--nextFoodCellIndex;
				if (nextFoodCellIndex == 0)
				{
					m_foodCell = CPoint(xWidth, yHeight);

					return;
				}
			}
		}
	}
	
	// TODO :: wrong situation
	assert(false);

	return;
}