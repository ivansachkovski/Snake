#pragma once

class GameView :
	public IView
{
public:
	explicit GameView(const std::shared_ptr<IModel>& pModel);

	void Update() override;
};