#pragma once

enum CellType
{
	eEmpty,
	eSnake,
	eFood
};

using Table = std::vector<std::vector<CellType>>;

class Point;

enum Direction
{
	eUp,
	eDown,
	eRight,
	eLeft,
	eUnknown
};

class ICommand
{

};

class IObserver
{
public:
	virtual void Update() = 0;
};

class IObserverable
{
private:
	std::vector<IObserver*> m_observers;

public:
	void AddObserver(IObserver* pObserver)
	{
		m_observers.push_back(pObserver);
	}

	void NotifyUpdate()
	{
		for (const auto& pObserver : m_observers)
		{
			pObserver->Update();
		}
	}
};

