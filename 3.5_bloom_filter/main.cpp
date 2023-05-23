#include <iostream>

#include "BloomFilter.hpp"

int main(void)
{
	BloomFilter bf(7);

	bf.insert(100);
	bf.insert(54);
	bf.insert(82);

	bf.lookup(5);
	bf.lookup(50);
	bf.lookup(20);
	bf.lookup(54);

	return 0;
}
