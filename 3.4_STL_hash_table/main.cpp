#include <iostream>
#include <unordered_map>
#include <unordered_set>

void print(const std::unordered_map<int, int>& map)
{
	for (const auto& element : map)
		std::cout << element.first << " => " << element.second << ",";
	std::cout << std::endl;
}

void print(const std::unordered_set<int>& set)
{
	for (const auto& element : set)
		std::cout << element << " ";
	std::cout << std::endl;
}

void find(const std::unordered_set<int>& container, const int element)
{
	if (container.find(element) != container.end())
		std::cout << "Found " << element << std::endl;
	else
		std::cout << "Not found " << element << std::endl;
}

void find(const std::unordered_map<int, int>& container, const int element)
{
	auto it = container.find(element);
	if (it == container.end())
		std::cout << "Not found " << element << std::endl;
	else
		std::cout << "Found " << element << "=>" << it->second << std::endl;
}

void setTest(void)
{
	std::cout << "Unordered Set" << std::endl;
	std::unordered_set<int> set = { 1, 2, 3, 4, 5 };

	std::cout << "Set: ";
	print(set);

	set.insert(10);
	set.insert(300);
	std::cout << "insert(10), insert(300): ";
	print(set);


	find(set, 4);
	find(set, 100);


	set.erase(2);
	std::cout << "erase(2): ";
	print(set);

	find(set, 2);
}

void mapTest(void)
{
	std::cout << "Unordered Map" << std::endl;
	std::unordered_map<int, int> map;

	map.insert({2, 4});
	map[3] = 9;
	std::cout << "insert{2, 4}, map[3] = 9: ";
	print(map);


	map[20] = 400;
	map[30] = 900;
	std::cout << "map[20] = 400, map[30] = 900: ";
	print(map);


	find(map, 10);
	find(map, 20);
	std::cout << "map[3] = " << map[3] << std::endl;
	std::cout << "map[100] = " << map[100] << std::endl;
	print(map);
}

int main(void)
{
	setTest();
	std::cout << std::endl;
	std::cout << std::endl;
	mapTest();

	return 0;
}
