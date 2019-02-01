#pragma once

class CPoint;


enum EDirection;


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

	virtual void PrintToConsole() const = 0;

};

