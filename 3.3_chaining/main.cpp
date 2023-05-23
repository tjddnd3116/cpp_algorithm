#include <iostream>

#include "Chaining.hpp"
#include "CuckooHash.hpp"

void chaining(void)
{
	Chaining map(7);

	auto print = [&map](int value)
	{
		if (map.find(value))
			std::cout << "Found " << value << std::endl;
		else
			std::cout << "Could not find " << value << std::endl;
	};

	map.insert(2);
	map.insert(25);
	map.insert(10);

	map.insert(100);
	map.insert(55);

	print(100);
	print(2);
	print(25);
	print(10);

	map.erase(2);

	print(2);

}

void cuckooHashing(void)
{
	CuckooHash map(7);

	std::cout << map << std::endl;

	map.insert(10);
	map.insert(20);
	map.insert(30);
	std::cout << std::endl;

	map.insert(104);
	map.insert(2);
	map.insert(70);
	map.insert(9);
	map.insert(90);
	map.insert(2);
	map.insert(7);
	std::cout << std::endl;

	std::cout << map << std::endl;

	map.insert(14);
}

int main(void)
{
	// chaining();

	cuckooHashing();

	return 0;
}
