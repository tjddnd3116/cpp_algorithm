#include "BinarySearch.hpp"
#include <cmath>

bool
BinarySearch::binarySearch(int n, std::vector<int>& s)
{
  std::vector<int>::iterator first = s.begin();
  std::vector<int>::iterator last = s.end();

  while (true)
  {
	auto rangeLength = std::distance(first, last);
	auto midElementIndex = std::floor(rangeLength / 2);
	auto midElement = *(first + midElementIndex);

	if (midElement == n)
	  return true;
	else if (midElement > n)
	  std::advance(last, -midElementIndex);
	else if (midElement < n)
	  std::advance(first, midElementIndex);

	if (rangeLength == 1)
	  return false;
  }
}
