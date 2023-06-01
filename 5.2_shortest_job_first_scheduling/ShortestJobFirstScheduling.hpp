#ifndef ShortestJobFirstScheduling_hpp
#define ShortestJobFirstScheduling_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template <typename T>
class ShortestJobFirstScheduling
{
	private:

	public:
	  static auto compute_waiting_times(std::vector<T>& service_times)
	  {
		std::vector<T> waiting_times(service_times.size());

		waiting_times[0] = 0;

		for (unsigned long i = 1; i < service_times.size(); ++i)
		  waiting_times[i] = waiting_times[i - 1] + service_times[i - 1];
		return waiting_times;
	  }

	  static void print_vector(std::vector<T>& vec)
	  {
		for (auto& i : vec)
		{
		  std::cout.width(2);
		  std::cout << i << " ";
		}
		std::cout << std::endl;
	  }

	  static void compute_and_print_waiting_times(std::vector<T>& service_times)
	  {
		auto waiting_times = compute_waiting_times(service_times);

		std::cout << "Service times: ";
		print_vector(service_times);

		std::cout << "Waiting times: ";
		print_vector(waiting_times);

		std::cout << "Average waiting time: "
		  << std::accumulate(waiting_times.begin(), waiting_times.end(), 0.0) / waiting_times.size()
		  << std::endl;
	  }
};
#endif //ShortestJobFirstScheduling_hpp
