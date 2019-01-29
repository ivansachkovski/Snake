#pragma once

class CField :
	public IField
{
private:
	size_t m_width;
	size_t m_height;

//	using Table = std::vector<std::vector<int>>;
//	Table m_field;

	std::unique_ptr<ISnake> m_pSnake;

	CPoint m_foodCell;

public:
	explicit CField(std::unique_ptr<ISnake>&&, size_t, size_t);
	
	bool Tic() override;
	
	void Print() override;

private:

	void GenerateNextFoodItem();
};