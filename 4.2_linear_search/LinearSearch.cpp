#include "LinearSearch.hpp"

bool
LinearSearch::linearSearch(int n, std::vector<int>& s)
{
  for (auto i : s)
  {
	if (i == n)
	  return true;
  }
  return false;
}
