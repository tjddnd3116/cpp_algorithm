#include <iostream>
#include "HashMap.hpp"

int main(void)
{
	HashMap map(10);

	auto print = [&](int value) {
		if (map.find(value)) {
			std::cout << value << " found" << std::endl;
		} else {
			std::cout << value << " not found" << std::endl;
		}
	};

	map.insert(1);
	map.insert(25);
	map.insert(10);
	print(25);

	map.insert(100);
	print(100);
	print(2);

	map.erase(25);
	print(25);
}
