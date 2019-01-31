#include "stdafx.h"

CField::CField(std::unique_ptr<ISnake>&& pSnake, size_t width, size_t height) :
	m_width(width),
	m_height(height),
	m_pSnake(std::move(pSnake)),
	m_foodCell(2, 2)
{
	m_pSnake->Init(CPoint(1, 1));
}


bool CField::Tic(int action)
{
	EDirection direction;
	switch (action)
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
	m_pSnake->Tic(direction);
	return true;
}


void CField::PrintToConsole()
{
	system("CLS");

	for (size_t yHeight = 1; yHeight <= m_height; ++yHeight)
	{
		for (size_t xWidth = 1; xWidth <= m_width; ++xWidth)
		{
			char cellValue = '.';
			if (m_foodCell.Equal(xWidth, yHeight))
			{
				cellValue = 'F';
			}
			else if (m_pSnake->Contain(CPoint(xWidth, yHeight)))
			{
				cellValue = '#';
			}
			printf("%c", cellValue);
		}
		printf("\n");
	}
}


void CField::GenerateNextFoodItem()
{
	size_t freeCellsAmount = (m_height * m_height) - m_pSnake->GetLength();
	
	size_t nextFoodCellIndex = (rand() % freeCellsAmount) + 1;
	
	for (size_t yHeight = 1; yHeight <= m_height; ++yHeight)
	{
		for (size_t xWidth = 1; xWidth <= m_width; ++xWidth)
		{
			if (m_pSnake->Contain(CPoint(xWidth, yHeight)))
			{

			}
		}
	}
}