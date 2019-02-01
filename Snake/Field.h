#pragma once

class CField :
	public IField
{
private:
	size_t m_width;
	size_t m_height;

	std::unique_ptr<ISnake> m_pSnake;

	CPoint m_foodCell;

public:
	explicit CField(std::unique_ptr<ISnake>&&, size_t, size_t);
	
	bool Tic(const int) override;
	
	void PrintToConsole() const override;

private:

	void GenerateNextFoodItem();

	EDirection ConvertActionToDirection(const int) const;

};

