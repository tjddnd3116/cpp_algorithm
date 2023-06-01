#include <iostream>
#include <vector>

#include "MergeSort.hpp"
#include "QuickSort.hpp"

void mergeSortTest(void)
{
  std::vector<int> s1 {45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7};
  std::vector<float> s2 {45.6f, 1.0f, 3.8f, 1.01f, 2.2f, 3.9f, 45.3f, 5.5f, 1.0f, 2.0f, 44.0f, 5.0f, 7.0f};
  std::vector<double> s3 {45.6, 1.0, 3.8, 1.01, 2.2, 3.9, 45.3, 5.5, 1.0, 2.0, 44.0, 5.0, 7.0};
  std::vector<char> c {'b', 'z', 'a', 'e', 'f', 't', 'q', 'u', 'y'};

  std::cout << "Unsorted: " << std::endl;
  MergeSort<int>::print(s1);
  MergeSort<float>::print(s2);
  MergeSort<double>::print(s3);
  MergeSort<char>::print(c);

  auto sorted1 = MergeSort<int>::mergeSort(s1);
  auto sorted2 = MergeSort<float>::mergeSort(s2);
  auto sorted3 = MergeSort<double>::mergeSort(s3);
  auto sorted4 = MergeSort<char>::mergeSort(c);

  std::cout << "Sorted: " << std::endl;
  MergeSort<int>::print(sorted1);
  MergeSort<float>::print(sorted2);
  MergeSort<double>::print(sorted3);
  MergeSort<char>::print(sorted4);
  std::cout << std::endl;

}

void quickSortTest(void)
{
  std::vector<int> s1 {45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7};
  std::vector<float> s2 {45.6f, 1.0f, 3.8f, 1.01f, 2.2f, 3.9f, 45.3f, 5.5f, 1.0f, 2.0f, 44.0f, 5.0f, 7.0f};
  std::vector<double> s3 {45.6, 1.0, 3.8, 1.01, 2.2, 3.9, 45.3, 5.5, 1.0, 2.0, 44.0, 5.0, 7.0};
  std::vector<char> c {'b', 'z', 'a', 'e', 'f', 't', 'q', 'u', 'y'};


  std::cout << "Unsorted: " << std::endl;
  QuickSort<int>::print(s1);
  QuickSort<float>::print(s2);
  QuickSort<double>::print(s3);
  QuickSort<char>::print(c);
  std::cout << std::endl;

  QuickSort<int>::quickSort(s1.begin(), s1.end() - 1);
  QuickSort<float>::quickSort(s2.begin(), s2.end() - 1);
  QuickSort<double>::quickSort(s3.begin(), s3.end() - 1);
  QuickSort<char>::quickSort(c.begin(), c.end() - 1);


  std::cout << "Sorted: " << std::endl;
  QuickSort<int>::print(s1);
  QuickSort<float>::print(s2);
  QuickSort<double>::print(s3);
  QuickSort<char>::print(c);
  std::cout << std::endl;
}

int main(void)
{
  quickSortTest();
  return 0;
}
