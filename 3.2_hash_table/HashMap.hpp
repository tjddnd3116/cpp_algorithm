#ifndef HashMap_hpp
#define HashMap_hpp

#include <iostream>
#include <vector>

class HashMap
{
		public:
			HashMap(size_t n);

			void insert(int value);
			bool find(int value);
			void erase(int value);

		private:
			std::vector<int> data;

};
#endif //HashMap_hpp
