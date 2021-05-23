#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<int,int> Pair;

void addEdge(vector <pair<int, int> > adj[], int vertex1, int vertex2, int weight)
{
	adj[vertex1].push_back(make_pair(vertex2,weight));
	adj[vertex2].push_back(make_pair(vertex1,weight));
}

void Prim(vector<pair<int,int>> adj[], int vertex)
{
	int source = 0;

    priority_queue<Pair,vector<Pair>,greater<Pair>> priority_queue;
	
    vector<int> key(vertex,INF);
	vector<int> parent(vertex,-1);
	vector<bool> in(vertex,false);

	priority_queue.push(make_pair(0,source));
	key[source] = 0;

	while(!priority_queue.empty())
	{
		int vertex_1 = priority_queue.top().second;
		priority_queue.pop();
		in[vertex_1] = true;

		for(auto x : adj[vertex_1])
		{
			int vertex_2 = x.first;
			int weight = x.second;

			if(in[vertex_2] == false && key[vertex_2] > weight)
			{
				key[vertex_2] = weight;
				priority_queue.push(make_pair(key[vertex_2],vertex_2));
				parent[vertex_2] = vertex_1;
			}
		}
	}
	for(int i=1; i<vertex; ++i)
    {
        printf("%d --- %d\n",parent[i],i);
    }
}

int main()
{
    int vertex1,vertex2,weight;
    int vertex,edges;
    int controll;
        
    ifstream input("graph.in");//catch the graph
    input >> vertex >> edges;//catch the number of vertex and edges
    vector<Pair> adj[vertex];
    
    for(controll=0;controll<edges;controll++)//fills the graph
    {
        input >> vertex1 >> vertex2 >> weight;
        addEdge(adj,vertex1,vertex2,weight);
    }
    printf("\n");
    printf("Minimum spanning tree:\n");
    printf("\n");
    Prim(adj,vertex);//run the Prim algorithm
    printf("\n");
}