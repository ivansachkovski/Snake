#include "stdafx.h"

CField::CField(std::unique_ptr<ISnake>&& pSnake, size_t width, size_t height):
	m_width(width),
	m_height(height)
{

}


bool CField::Tic()
{
	return true;
}


void CField::Print()
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
			else
			{

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