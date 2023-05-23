#include <iostream>
#include "Graph.hpp"

using namespace std;

int main()
{
	Graph g(static_cast<int>(city::SIZE));

	g.addEdge(city::LONDON, city::MOSCOW, 2500);
	g.addEdge(city::LONDON, city::SEOUL, 9000);
	g.addEdge(city::LONDON, city::DUBAI, 5500);
	g.addEdge(city::SEOUL, city::MOSCOW, 6600);
	g.addEdge(city::SEOUL, city::SEATTLE, 8000);
	g.addEdge(city::SEOUL, city::DUBAI, 7000);
	g.addEdge(city::SEOUL, city::SYDNEY, 8000);
	g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
	g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
	g.addEdge(city::DUBAI, city::SYDNEY, 1200);

	g.addEdge(city::SEATTLE, city::LONDON, 8000);
	g.removeEdge(city::SEATTLE, city::LONDON);

	// g.addEdgeToList(city::LONDON, city::MOSCOW, 2500);
	// g.addEdgeToList(city::LONDON, city::SEOUL, 9000);
	// g.addEdgeToList(city::LONDON, city::DUBAI, 5500);
	// g.addEdgeToList(city::SEOUL, city::MOSCOW, 6600);
	// g.addEdgeToList(city::SEOUL, city::SEATTLE, 8000);
	// g.addEdgeToList(city::SEOUL, city::DUBAI, 7000);
	// g.addEdgeToList(city::SEOUL, city::SYDNEY, 8000);
	// g.addEdgeToList(city::SEATTLE, city::MOSCOW, 8400);
	// g.addEdgeToList(city::SEATTLE, city::SYDNEY, 12000);
	// g.addEdgeToList(city::DUBAI, city::SYDNEY, 1200);
    //
	// g.addEdgeToList(city::SEATTLE, city::LONDON, 8000);
	// g.removeEdgeToList(city::SEATTLE, city::LONDON);

	return (0);
}
