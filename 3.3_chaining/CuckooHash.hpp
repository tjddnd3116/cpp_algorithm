#ifndef CuckooHash_hpp
#define CuckooHash_hpp

#include <iostream>
#include <vector>

class CuckooHash
{
		friend std::ostream& operator<<(std::ostream& os, const CuckooHash& obj);

		public:
			CuckooHash(int n);

			int							hash1(int key) const;
			int							hash2(int key) const;
			std::vector<int>::iterator	lookup(int key);
			void						erase(int key);
			void						insert(int key);
			void						insertRecursive(int key, int cnt = 0, int table = 1);
			void						print(void);

		private:
			const std::vector<int>&		getData(int index) const;

			std::vector<int>	m_data1;
			std::vector<int>	m_data2;
			int					m_size;

};
#endif //CuckooHash_hpp
