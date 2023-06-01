#include <chrono>
#include <iostream>
#include <random>

#include "LinearSearch.hpp"
#include "BinarySearch.hpp"

void runSmallSearchTest(void)
{
  auto n = 2;
  std::vector<int> s {1, 3, 2, 4, 5, 7, 9, 8, 6};

  std::sort(s.begin(), s.end());

  if (LinearSearch::linearSearch(n, s))
	  std::cout << "LinearSearch found " << n << std::endl;
  else
	  std::cout << "LinearSearch did not find " << n << std::endl;

  if (BinarySearch::binarySearch(n, s))
	std::cout << "BinarySearch found " << n << std::endl;
  else
	std::cout << "BinarySearch did not find " << n << std::endl;
}

void runLargeSearchTest(int size, int n)
{
  std::vector<int> s;
  std::random_device rd;
  std::mt19937 rand(rd());

  std::uniform_int_distribution<std::mt19937::result_type> uniformDist(1, size);

  for (auto i = 0; i < size; i++)
	s.push_back(uniformDist(rand));

  std::sort(s.begin(), s.end());

  std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

  bool searchResult = BinarySearch::binarySearch(n, s);
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "BinarySearch took " << diff.count() << " nanoseconds" << std::endl;

  if (searchResult)
	std::cout << "BinarySearch found " << n << std::endl;
  else
	std::cout << "BinarySearch did not find " << n << std::endl;
}


int main(void)
{
  runSmallSearchTest();

  runLargeSearchTest(100000, 36543);
  runLargeSearchTest(1000000, 36543);
  runLargeSearchTest(10000000, 36543);

  return 0;
}
