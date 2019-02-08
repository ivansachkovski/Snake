#pragma once

class SnakeHandler :
	public IField
{
private:
	size_t m_width;
	size_t m_height;

	std::unique_ptr<ISnake> m_pSnake;

	CPoint m_foodCell;

public:
	explicit SnakeHandler(std::unique_ptr<ISnake>&&, size_t, size_t);
	
	bool Tic(const int) override;
	

private:

	void GenerateNextFoodItem();

	EDirection ConvertActionToDirection(const int) const;
};
