#include "stdafx.h"

GameModel::GameModel(size_t tableHeight, size_t tableWidth) :
	m_tableHeight(tableHeight),
	m_tableWidth(tableWidth),
	m_pSnake(new Snake())
{
	m_pSnake->Init(Point(0, 0));
}

void GameModel::Tic()
{
	m_pSnake->Tic(m_targetCell);
	
	GenerateNextTarget();

	NotifyUpdate();
}

void GameModel::GetTable(Table& table) const
{
	table.Resize(m_tableHeight, m_tableWidth);

	table.Clear();
	
	table.PlaceTarget(m_targetCell);

	table.PlaceSnake(m_pSnake->begin(), m_pSnake->end());
}

void GameModel::GenerateNextTarget()
{
	if (m_targetCell.IsValid())
	{
		return;
	}

	int freeCellsAmount = (m_tableHeight * m_tableWidth) - m_pSnake->size() + 1;

	if (!freeCellsAmount)
	{
		// The game is completed
		throw "You've won! Congratulations!";
	}

	int nextFoodCellIndex = (rand() % freeCellsAmount);

	for (size_t yHeight = 0; yHeight < m_tableHeight; ++yHeight)
	{
		for (size_t xWidth = 0; xWidth < m_tableWidth; ++xWidth)
		{
			if (!m_pSnake->Contains(Point(xWidth, yHeight), false))
			{
				if (nextFoodCellIndex == 0)
				{
					m_targetCell = Point(xWidth, yHeight);

					return;
				}

				--nextFoodCellIndex;
			}
		}
	}

	// TODO :: wrong situation
	assert(false);

	return;
}

void GameModel::ChangeDirectionTo(const Direction direction)
{
	m_pSnake->TryToRotate(direction);
}