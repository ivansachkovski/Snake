#pragma once

class GameView :
	public IObserver
{
private:
	GameModel* m_pModel;

public:
	explicit GameView(GameModel* pModel);

	void Update();
};