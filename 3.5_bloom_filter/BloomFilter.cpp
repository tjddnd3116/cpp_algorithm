#include "BloomFilter.hpp"

BloomFilter::BloomFilter(int n)
	:m_nBits(n)
{
	if (n > 64)
	{
		std::cout << "Error: BloomFilter only supports up to 64 bits." << std::endl;
		exit(-1);
	}
	m_data = 0;
}

int
BloomFilter::hash(int num, int key)
{
	switch (num)
	{
		case 0: return key % m_nBits;
		case 1: return (key / 7) % m_nBits;
		case 2: return (key / 11) % m_nBits;
	}
	return 0;
}

void BloomFilter::lookup(int key)
{
	int h0 = hash(0, key);
	int h1 = hash(1, key);
	int h2 = hash(2, key);
	unsigned long long mask = 1;
	int result = (m_data & (mask << h0)) && (m_data & (mask << h1)) && (m_data & (mask << h2));

	if (result)
		std::cout << key << " Maybe" << std::endl;
	else
		std::cout << key << " Never" << std::endl;
}

void BloomFilter::insert(int key)
{
	m_data |= (1 << hash(0, key));
	m_data |= (1 << hash(1, key));
	m_data |= (1 << hash(2, key));

	std::cout << "Inserted " << key << std::endl;

	for (int i = 0; i < m_nBits; i++)
		std::cout << i << " ";
	std::cout << std::endl;

	unsigned long long mask = 1;
	for (int cnt = 0; cnt < m_nBits; mask <<= 1, cnt++)
		std::cout << ((m_data & mask) != 0) << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}
