#include <iostream>

#include "ShortestJobFirstScheduling.hpp"

int main(void)
{
  std::vector<int> service_times {8, 1, 2, 4, 9, 2, 3, 5};

  std::cout << "Service times and waiting times" << std::endl;;
  ShortestJobFirstScheduling<int>::compute_and_print_waiting_times(service_times);

  std::sort(service_times.begin(), service_times.end());

  std::cout << std::endl;
  std::cout << "Service times and waiting times after sorting" << std::endl;;
  ShortestJobFirstScheduling<int>::compute_and_print_waiting_times(service_times);

  return 0;
}
