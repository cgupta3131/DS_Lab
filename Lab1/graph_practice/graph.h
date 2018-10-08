#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
	int v; //count the number of vertices present!
	bool adj[20][20];
	
public:
	Graph(int vcount); //Constructor 
	void addEdge(int source, int dest); //Functions
	void deleteEdge(int source, int dest); // Functions
	void BFS(int s); // Functions

};



Graph::Graph(int vcount)//::means that go into Graph class and find the function Graph
//We need to use :: if we are declaring our functions outside the class as without
// this the compiler will take as if Graph belongs to std which would give ann error!
{
	this->v=vcount;
	for(int i=0; i<v;i++)
		for(int j=0; j<v; j++)
			adj[i][j]=false;
}

void Graph::addEdge(int source, int dest)
{ 
	//forming a non-directed Graph!
	adj[source][dest]=true;
	adj[dest][source]=true;
}

void Graph::deleteEdge(int source, int dest)
{
	adj[source][dest]=false;
	adj[dest][source]=false;
}

void Graph::BFS(int s) //where s is a source
{
	bool *visited= new bool[this->v];
	for(int i=0;i<this->v;i++)
		visited[i] = false;

	int *bfsOrder= new int[this->v];
	int q[100];
	int front=0;
	int back=0;

	visited[s]=true;
	q[back]=s;
	back++;
	int x = 0;

	while(front != back)
	{	
		int element = q[front++]; //pop operation
		bfsOrder[x] = element;
		cout << element << " ";
		x++;

		for(int i=0;i<20;i++)
		{
			if(adj[element][i] && !visited[i]) // that is there is an edge!
			{
				q[back] = i; //push operation
				back++;
				visited[i] = true;
			}
		}
	}

	cout << endl;
}
	











