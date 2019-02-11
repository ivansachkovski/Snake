#pragma once

class GameModel :
	public IObserverable
{
	SnakeHandler* m_pSnakeHandler;

public:
	explicit GameModel();

	void Move();

	void GetTable(Table& table) const;
};