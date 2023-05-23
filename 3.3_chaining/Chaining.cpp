#include "Chaining.hpp"

Chaining::Chaining(size_t n)
{
	data.resize(n);
}

void Chaining::insert(int value)
{
	int n = data.size();

	data[value % n].push_back(value);
	std::cout << "Inserted " << value << " at index " << value % n << std::endl;
}

bool Chaining::find(int value)
{
	int n = data.size();

	auto& entries = data[value % n];
	return (std::find(entries.begin(), entries.end(), value) != entries.end());
}

void Chaining::erase(int value)
{
	int n = data.size();

	auto& entries = data[value % n];
	auto it = std::find(entries.begin(), entries.end(), value);
	if (it != entries.end())
	{
		entries.erase(it);
		std::cout << "Erased " << value << " at index " << value % n << std::endl;
	}
	else
	{
		std::cout << "Could not find " << value << " at index " << value % n << std::endl;
	}
}
