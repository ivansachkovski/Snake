#pragma once

class Snake
{
private:
	using PointsQueue = std::deque<CPoint>;
	PointsQueue m_body;

	Direction m_direction;

public:
	explicit Snake();

	~Snake() = default;

	void Init(const CPoint&);

	bool Tic(const Direction, CPoint& foodCell);

	void Grow();

	bool Contains(const CPoint&, bool) const;

	size_t GetLength() const;

	CPoint GetHead() const;

	void CheckForGrowth(CPoint& foodCell);

private:

	void ChangeDirection(const Direction);

	void ChangePosition();
};