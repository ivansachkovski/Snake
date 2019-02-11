#pragma once

class Snake :
	public std::deque<Point>
{
private:

	Direction m_direction = eRight;

	// Mutex is used to get access to m_direction
	std::mutex m_mutex;
	
public:

	void Init(const Point&);

	bool Tic(Point& targetCell);

	void GrowUp();

	bool Contains(const Point&, bool) const;

	void CheckForGrowth(Point& foodCell);

	void TryToRotate(const Direction);

private:

	void MoveForward();
};
