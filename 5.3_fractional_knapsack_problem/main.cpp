#include <iostream>
#include <vector>

#include "Object.hpp"


auto fill_knapsack(std::vector<Object>& objects, int knapsack_capacity)
{
  std::vector<Object> knapsack_contents;
  knapsack_contents.reserve(objects.size());

  std::sort(objects.begin(), objects.end());
  std::reverse(objects.begin(), objects.end());

  auto current_object = objects.begin();
  int current_total_weight = 0;
  while (current_total_weight < knapsack_capacity && current_object != objects.end())
  {
	knapsack_contents.push_back(*current_object);

	current_total_weight += current_object->weight;
	current_object++;
  }

  int weight_of_last_obj_to_remove = current_total_weight - knapsack_capacity;

  Object& last_obj = knapsack_contents.back();
  if (weight_of_last_obj_to_remove > 0)
  {
	last_obj.weight -= weight_of_last_obj_to_remove;
	last_obj.value -= last_obj.value_per_unit_weight * weight_of_last_obj_to_remove;
  }
  return knapsack_contents;
}

int main(void)
{
  std::vector<Object> obj;
  obj.reserve(7);

  std::vector<int> weights {1, 2, 5, 9, 2, 3, 4};
  std::vector<double> values {10, 7, 15, 10, 12, 11, 5};
  for (auto i = 0; i < 7; i++)
	obj.push_back(Object(i + 1, weights[i], values[i]));

  std::cout << "물건 목록" << std::endl;
	for (auto& o : obj)
		std::cout << o << std::endl;

	std::cout << std::endl << "무게 제한: 7" << std::endl;
	int knapsack_capacity = 7;
	auto knapsack_contents = fill_knapsack(obj, knapsack_capacity);
	std::cout << "[배낭에 넣을 물건들 (최대 용량= " << knapsack_capacity << ")]" << std::endl;
	for (auto& o : knapsack_contents)
		std::cout << o << std::endl;
	std::cout << std::endl;
}
