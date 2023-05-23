#include "CuckooHash.hpp"

CuckooHash::CuckooHash(int n)
	: m_size(n)
{
	m_data1 = std::vector<int>(m_size, -1);
	m_data2 = std::vector<int>(m_size, -1);
}

int CuckooHash::hash1(int key) const
{
	return key % m_size;
}

int CuckooHash::hash2(int key) const
{
	return (key / m_size) % m_size;
}

std::vector<int>::iterator
CuckooHash::lookup(int key)
{
	auto hash_value1 = hash1(key);

	if (m_data1[hash_value1] == key)
	{
		std::cout << "Found first hash table " << key << " at index " << hash_value1 << std::endl;
		return m_data1.begin() + hash_value1;
	}

	auto hash_value2 = hash2(key);

	if (m_data1[hash_value2] == key)
	{
		std::cout << "Found second hash table " << key << " at index " << hash_value2 << std::endl;
		return m_data2.begin() + hash_value2;
	}

	std::cout << "Not Found " << key << std::endl;
	return m_data2.end();
}

void
CuckooHash::erase(int key)
{
	auto position = lookup(key);

	if (position != m_data2.end())
	{
		*position = -1;
		std::cout << "Erased " << key << std::endl;
		return;
	}
	std::cout << "Could not find " << key << std::endl;
}

void
CuckooHash::insert(int key)
{
	insertRecursive(key);
}

void
CuckooHash::insertRecursive(int key, int cnt, int table)
{
	if (cnt >= m_size)
	{
		std::cout << "Could not insert " << key << " need to re-hashing" << std::endl;
		return;
	}

	if (table)
	{
		auto hashValue = hash1(key);

		if (m_data1[hashValue] == -1)
		{
			m_data1[hashValue] = key;
			std::cout << "Inserted to first hash table " << key << " at index " << hashValue << std::endl;
			return;
		}
		else
		{
			auto oldKey = m_data1[hashValue];
			m_data1[hashValue] = key;
			std::cout << "Inserted to first hash table " << key << " at index " << hashValue << std::endl;
			std::cout << "old key " << oldKey << " at index " << hashValue << " moved to => " << std::endl << '\t';
			insertRecursive(oldKey, cnt + 1, !table);
		}
	}
	else
	{
		auto hashValue = hash2(key);

		if (m_data2[hashValue] == -1)
		{
			m_data2[hashValue] = key;
			std::cout << "Inserted to second hash table " << key << " at index " << hashValue << std::endl;
			return;
		}
		else
		{
			auto oldKey = m_data2[hashValue];
			m_data2[hashValue] = key;
			std::cout << "Inserted to second hash table " << key << " at index " << hashValue << std::endl;
			std::cout << "old key " << oldKey << " at index " << hashValue << " moved to => " << std::endl << '\t';
			insertRecursive(oldKey, cnt + 1, !table);
		}
	}
}

const std::vector<int>&
CuckooHash::getData(int index) const
{
	if (index == 1)
		return m_data1;
	return m_data2;
}

std::ostream& operator<<(std::ostream& os, const CuckooHash& obj)
{
	os << "Index: ";
	for (int i = 0; i < obj.m_size; ++i)
	{
		os << i << '\t';
	}
	os << std::endl;

	os<< "Table 1: ";
	for (auto &i : obj.getData(1))
		os << i << '\t';
	os << std::endl;

	os<< "Table 2: ";
	for (auto &i : obj.getData(2))
		os << i << '\t';
	os << std::endl;

	return os;
}


