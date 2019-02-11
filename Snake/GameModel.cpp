#include "stdafx.h"

GameModel::GameModel()
{

}

void GameModel::Move()
{
	//m_pSnakeHandler->Tic(10);
	NotifyUpdate();
}

void GameModel::GetTable(Table& table) const
{
	//m_pSnakeHandler->
}