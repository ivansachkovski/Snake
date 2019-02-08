#pragma once

using Table = std::vector<std::vector<int>>;

class CPoint;


enum EDirection
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


class ISnake
{
public:
	virtual void Init(const CPoint& point) = 0;

	virtual bool Tic(const EDirection direction, CPoint& foodCell) = 0;

	virtual bool Contains(const CPoint& point, bool bCheckAsHead) const = 0;

	virtual void Grow() = 0;

	virtual size_t GetLength() const = 0;

	virtual CPoint GetHead() const = 0;
};


class IField
{
public:
	virtual bool Tic(const int actionCode) = 0;
};


class IObserver
{
public:
	virtual void Update() = 0;
};


class IObserverable
{
private:
	std::vector<std::shared_ptr<IObserver>> m_observers;

public:
	void AddObserver(const std::shared_ptr<IObserver>& pObserver)
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


class IModel : 
	public IObserverable
{
public:
	virtual void Move() = 0;
};


class IView :
	public IObserver
{
private:
	std::shared_ptr<IModel> m_pModel;

public:
	IView(const std::shared_ptr<IModel>& pModel) :
		m_pModel(pModel)
	{

	}
};


class IController
{
protected:
	std::shared_ptr<IModel> m_pModel;

public:
	IController(const std::shared_ptr<IModel>& pModel) :
		m_pModel(pModel)
	{

	}

};