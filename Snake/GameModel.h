#pragma once

class GameModel : 
	public IModel
{
	std::unique_ptr<IField> m_pField;

public:
	explicit GameModel();

	void Move() override;
};