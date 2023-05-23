#include "HashMap.hpp"

HashMap::HashMap(size_t n)
{
	data = std::vector<int>(n, -1);
}

void HashMap::insert(int value)
{
	int n = data.size();

	data[value % n] = value;
	std::cout << value << " inserted at " << value % n << std::endl;
}

bool HashMap::find(int value)
{
	int n = data.size();

	return (data[value % n] == value);
}

void HashMap::erase(int value)
{
	int n = data.size();

	if (this->find(value)) {
		data[value % n] = -1;
		std::cout << value << " erased from " << value % n << std::endl;
	} else {
		std::cout << value << " not found" << std::endl;
	}
}
