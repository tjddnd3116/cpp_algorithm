#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <vector>
#include <iostream>

template <typename T>
class QuickSort
{
	private:

	public:
	  static auto partition(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end)
	  {
		auto pivotVal = *begin;
		auto leftIter = begin + 1;
		auto rightIter = end;

		while (1)
		{
		  while (*leftIter <= pivotVal && std::distance(leftIter, rightIter) > 0)
			leftIter++;
		  while (*rightIter > pivotVal && std::distance(leftIter, rightIter) > 0)
			rightIter--;

		  if (leftIter == rightIter)
			break;
		  else
			std::iter_swap(leftIter, rightIter);
		}
		if (pivotVal > *rightIter)
		  std::iter_swap(begin, rightIter);
		return rightIter;
	  }

	  static void quickSort(typename std::vector<T>::iterator begin,
		  typename std::vector<T>::iterator last)
	  {
		if (std::distance(begin, last) <= 0)
		  return;
		auto partitionIter = partition(begin, last);

		quickSort(begin, partitionIter - 1);
		quickSort(partitionIter, last);
	  }

	  static void print(std::vector<T> arr)
	  {
		for (auto i : arr)
		  std::cout << i << " ";

		std::cout << std::endl;
	  }
};
#endif //QuickSort_hpp
