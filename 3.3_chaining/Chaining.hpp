#ifndef Chaining_hpp
#define Chaining_hpp

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class Chaining
{
		public:
			Chaining(size_t n);
			void insert(int value);
			bool find(int value);
			void erase(int value);
			void print();
		private:
			std::vector<std::list<int>> data;
};
#endif //Chaining_hpp
