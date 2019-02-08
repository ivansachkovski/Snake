#pragma once

class GameModel : 
	public IModel
{
	SnakeHandler* m_pSnakeHandler;

public:
	explicit GameModel();

	void Move() override;
};