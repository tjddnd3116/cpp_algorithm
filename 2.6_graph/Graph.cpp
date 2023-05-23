#include "Graph.hpp"

Graph::Graph(int n)
{
	matrix.reserve(n);
	std::vector<int> row(n);
	std::fill(row.begin(), row.end(), -1);

	for (int i = 0; i < n; ++i)
	{
		matrix.push_back(row);
	}

	adjacencyList = std::vector<std::vector<std::pair<int, int>>>(n, std::vector<std::pair<int, int>>());
}

void Graph::addEdge(city c1, city c2, int dis)
{
	std::cout << "add edge from " << c1 << " to " << c2 << " with dis " << dis << std::endl;

	auto n1 = static_cast<int>(c1);
	auto n2 = static_cast<int>(c2);
	matrix[n1][n2] = dis;
	matrix[n2][n1] = dis;
}

void Graph::removeEdge(city c1, city c2)
{
	std::cout << "remove edge from " << c1 << " to " << c2 << std::endl;

	auto n1 = static_cast<int>(c1);
	auto n2 = static_cast<int>(c2);
	matrix[n1][n2] = -1;
	matrix[n2][n1] = -1;
}

void Graph::addEdgeToList(city c1, city c2, int dis)
{
	std::cout << "add edge from " << c1 << " to " << c2 << " with weight " << dis << std::endl;

	auto n1 = static_cast<int>(c1);
	auto n2 = static_cast<int>(c2);

	adjacencyList[n1].push_back({n2, dis});
	adjacencyList[n2].push_back({n1, dis});

}

void Graph::removeEdgeToList(city c1, city c2)
{
	std::cout << "remove edge from " << c1 << " to " << c2 << std::endl;

	auto n1 = static_cast<int>(c1);
	auto n2 = static_cast<int>(c2);

	std::remove_if(adjacencyList[n1].begin(), adjacencyList[n1].end(), [n2](const std::pair<int, int>& p){
			return p.first == n2;
			});
	std::remove_if(adjacencyList[n2].begin(), adjacencyList[n2].end(), [n1](const std::pair<int, int>& p) {
			return p.first == n1;
			});
}
