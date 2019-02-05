#pragma once

class CSnake : 
	public ISnake
{
private:
	using PointsQueue = std::deque<CPoint>;
	PointsQueue m_body;

	EDirection m_direction;

public:
	explicit CSnake();

	~CSnake() = default;

	void Init(const CPoint&) override;

	bool Tic(const EDirection, CPoint& foodCell) override;

	void Grow() override;

	bool Contains(const CPoint&, bool) const override;

	size_t GetLength() const override;

	CPoint GetHead() const override;

	void CheckForGrowth(CPoint& foodCell);

private:

	void ChangeDirection(const EDirection);

	void ChangePosition();
};