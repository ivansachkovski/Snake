#pragma once

// Class Table is used to transfer data from Model to View
class Table :
	public std::vector<std::vector<CellType>>
{
private:

public:
	void Resize(size_t height, size_t width)
	{
		if (this->size() != height)
		{
			this->resize(height);
		}

		for (auto& row : *this)
		{
			if (row.size() != width)
			{
				row.resize(width);
			}
		}
	}

	void Clear()
	{
		for (auto& row : *this)
		{
			for (auto& cell : row)
			{
				cell = eEmpty;
			}
		}
	}

	void PlaceTarget(const Point& targetCell)
	{
		size_t tableHeight = this->size();
		size_t tableWidth = (this->size()) ? this->begin()->size() : 0;
		
		if (targetCell.IsValid(tableHeight, tableWidth))
		{
			(*this)[targetCell.GetY()][targetCell.GetX()] = eTarget;
		}
		else
		{
			assert(false);
		}
	}

	void PlaceSnake(std::deque<Point>::iterator first, std::deque<Point>::iterator last)
	{
		size_t tableHeight = this->size();
		size_t tableWidth = (this->size()) ? this->begin()->size() : 0;

		while (first != last)
		{
			if (first->IsValid(tableHeight, tableWidth))
			{
				(*this)[first->GetY()][first->GetX()] = eSnake;
			}
			else
			{
				assert(false);
			}

			++first;
		}
	}
};