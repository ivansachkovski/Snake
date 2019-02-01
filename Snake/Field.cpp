#include "stdafx.h"

CField::CField(std::unique_ptr<ISnake>&& pSnake, size_t width, size_t height) :
	m_width(width),
	m_height(height),
	m_pSnake(std::move(pSnake)),
	m_foodCell(2, 2)
{
	m_pSnake->Init(CPoint(1, 1));
}


bool CField::Tic(const int actionCode)
{
	EDirection direction = eUnknown;
	direction = ConvertActionToDirection(actionCode);
	
	m_pSnake->Tic(direction);

	if (m_pSnake->GetHead().EqualTo(m_foodCell))
	{
		m_pSnake->Grow();
		GenerateNextFoodItem();
	}

	return true;
}


EDirection CField::ConvertActionToDirection(const int actionCode) const
{
	EDirection direction;

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

void CField::PrintToConsole() const
{
	// Free screen
	system("CLS");

	// Print current state
	for (size_t yHeight = 1; yHeight <= m_height; ++yHeight)
	{
		for (size_t xWidth = 1; xWidth <= m_width; ++xWidth)
		{
			char cellValue = '.';
			if (m_foodCell.EqualTo(xWidth, yHeight))
			{
				cellValue = 'F';
			}
			if (m_pSnake->Contains(CPoint(xWidth, yHeight)))
			{
				cellValue = '#';
			}
			printf("%c", cellValue);
		}
		printf("\n");
	}

	return;
}


void CField::GenerateNextFoodItem()
{
	int freeCellsAmount = (m_height * m_width) - m_pSnake->GetLength();
	
	size_t nextFoodCellIndex = (rand() % freeCellsAmount) + 1;
	
	for (size_t yHeight = 1; yHeight <= m_height; ++yHeight)
	{
		for (size_t xWidth = 1; xWidth <= m_width; ++xWidth)
		{
			if (!m_pSnake->Contains(CPoint(xWidth, yHeight)))
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

	return;
}