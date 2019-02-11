#pragma once

class SnakeHandler
{
private:
	size_t m_width;
	size_t m_height;

	std::unique_ptr<Snake> m_pSnake;

	CPoint m_foodCell;

public:
	explicit SnakeHandler(std::unique_ptr<Snake>&&, size_t, size_t);
	
	bool Tic(const int);
	

private:

	void GenerateNextFoodItem();

	Direction ConvertActionToDirection(const int) const;
};
