#pragma once

class CField
{
private:
	size_t m_length;
	size_t m_height;

	using Table = std::vector<std::vector<int>>;
	Table m_field;

public:
	explicit CField(size_t length, size_t hight);
	void GenerateFood();
};