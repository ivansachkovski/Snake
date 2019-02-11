#include "stdafx.h"

GameView::GameView(GameModel* pModel) :
	m_pModel(pModel)
{

}

void GameView::Update()
{
	static Table table;

	system("CLS");

	m_pModel->GetTable(table);

	for (const auto& row : table)
	{
		for (const auto& cellType : row)
		{
			char cellView = 0;

			switch (cellType)
			{
			case eEmpty:
				cellView = '.';
				break;
			case eSnake:
				cellView = '#';
				break;
			case eFood:
				cellView = 'F';
				break;
			default:
				assert(false);
				break;
			}
			
			std::cout << cellView;
		}
		std::cout << std::endl;
	}
}