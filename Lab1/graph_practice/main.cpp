#include <cstdlib>

#include "graph.h"
using namespace std;

int main(){

	Graph *g=new Graph(10);
	g->addEdge(0,11);
	g->addEdge(0,10);
	g->addEdge(0,3);
	g->addEdge(3,4);
	g->addEdge(3,5);
	g->addEdge(3,6);
	g->addEdge(3,7);
	g->addEdge(3,8);
	g->addEdge(3,9);
	g->BFS(0);
	return(0);
}
