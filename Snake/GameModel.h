#pragma once

class GameModel :
	public IObserverable
{
	size_t m_tableHeight;
	size_t m_tableWidth;

	std::unique_ptr<Snake> m_pSnake;

	Point m_targetCell;

public:
	explicit GameModel(size_t tableHeight, size_t tableWidth);

	void Tic();

	void GetTable(Table& table) const;

	void GenerateNextTarget();

	void ChangeDirectionTo(const Direction direction);
};