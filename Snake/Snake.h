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

	void Tic(const EDirection) override;

	void Grow() override;

	bool Contains(const CPoint&) const override;

	size_t GetLength() const override;

	CPoint GetHead() const override;

private:

	void ChangeDirection(const EDirection);

	void ChangePosition();

};