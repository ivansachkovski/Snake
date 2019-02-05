#pragma once

class CGameView :
	public IView
{
public:
	CGameView(const std::shared_ptr<IModel>& pModel);

	void Update() override;
};