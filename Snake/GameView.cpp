#include "stdafx.h"

CGameView::CGameView(const std::shared_ptr<IModel>& pModel) :
	IView(pModel)
{

}

void CGameView::Update()
{
	system("CLS");

	std::vector<std::vector<int>> s;
}