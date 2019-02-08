#include "stdafx.h"

GameView::GameView(const std::shared_ptr<IModel>& pModel) :
	IView(pModel)
{

}

void GameView::Update()
{
	system("CLS");

	std::vector<std::vector<int>> s;
}