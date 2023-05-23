#ifndef Graph_hpp
#define Graph_hpp

#include <algorithm>
#include <iostream>
#include <vector>

enum class city: int
{
	MOSCOW,
	LONDON,
	SEOUL,
	SEATTLE,
	DUBAI,
	SYDNEY,
	SIZE,
};

class Graph
{
		private:
			std::vector<std::vector<int>> matrix;
			std::vector<std::vector<std::pair<int, int>>> adjacencyList;
		public:
			Graph(int n);
			void addEdge(city c1, city c2, int weight);
			void removeEdge(city c1, city c2);
			void addEdgeToList(city c1, city c2, int weight);
			void removeEdgeToList(city c1, city c2);
};

inline std::ostream& operator<<(std::ostream& os, const city& c)
{
	switch (c)
	{
		case city::LONDON:
			os << "London";
			return os;
		case city::MOSCOW:
			os << "Moscow";
			return os;
		case city::SEOUL:
			os << "Seoul";
			return os;
		case city::SEATTLE:
			os << "Seattle";
			return os;
		case city::DUBAI:
			os << "Dubai";
			return os;
		case city::SYDNEY:
			os << "Sydney";
			return os;
		default:
			return os;
	}
}

#endif //graph_hpp
