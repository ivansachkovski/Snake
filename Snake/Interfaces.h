#pragma once

enum CellType
{
	eEmpty,
	eSnake,
	eTarget
};

enum ExceptionType
{
	eError,
	eSuccess
};

struct Exception : public std::exception
{
	std::string m_message;
	ExceptionType m_type;

	Exception(const std::string& message, const ExceptionType type) :
		m_message(message),
		m_type(type)
	{

	}
};

enum Direction
{
	eUp,
	eDown,
	eRight,
	eLeft,
	eUnknown
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

