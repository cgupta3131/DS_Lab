#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Graph
{
	int v;
	bool **adj;
	public:
		Graph(int vcount);
		void addEdge(int u,int v);
		void deleteEdge(int u,int v);
		vector<int> BFS(int s);
		vector<int> DFS(int s);
		void DFSUtil(int s,vector<int> &dfs,vector<bool> &visited);
};

Graph::Graph(int vcount)
{
	this->v = vcount;
	this->adj=new bool*[vcount];
	for(int i=0;i<vcount;i++)
		this->adj[i]=new bool[vcount];
	for(int i=0;i<vcount;i++)
		for(int j=0;j<vcount;j++)
			adj[i][j]=false;
}

void Graph::addEdge(int u,int w)
{
	this->adj[u][w]=true;
	this->adj[w][u]=true;
}

void Graph::deleteEdge(int u,int w)
{
	this->adj[u][w]=false;
	this->adj[w][u]=false;
}

vector<int> Graph::BFS(int s)
{
	vector<bool> visited(this->v);
	for(int i=0;i<visited.size();i++)
		visited[i] = false;

	vector<int> bfs;
	queue<int> que;
	que.push(s);
	visited[s]=true;

	while(!que.empty())
	{
		bfs.push_back(que.front());
		for(int i=0;i<this->v;i++)
		{
			if(adj[que.front()][i] && !visited[i])
			{
				visited[i]=true;
				que.push(i);
			}
		}
		que.pop();
	}
	return bfs;
}

void Graph::DFSUtil(int s, vector<int> &dfs, vector<bool> &visited)
{
	visited[s]=true;
	dfs.push_back(s);
	for(int i=0;i<this->v;i++)
	{
		if(this->adj[s][i] && !visited[i])
			DFSUtil(i,dfs,visited);
	}
}

vector<int> Graph::DFS(int s)
{
	vector<bool> visited(this->v);
	for(int i=0;i<visited.size();i++)
		visited[i] = false;

	vector<int> dfs;
	DFSUtil(s,dfs,visited);
	return dfs;
}
