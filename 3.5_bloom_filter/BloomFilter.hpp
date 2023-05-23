#ifndef BloomFilter_hpp
#define BloomFilter_hpp

#include <iostream>
#include <vector>

class BloomFilter
{
		public:
			BloomFilter(int n);

			int hash(int num, int key);
			void lookup(int key);
			void insert(int key);

		private:
			unsigned long long m_data;
			int m_nBits;

};
#endif //BloomFilter_hpp
