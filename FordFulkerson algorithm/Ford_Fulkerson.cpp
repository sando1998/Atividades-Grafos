#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <bits/stdc++.h>

using namespace std;
#define constant 5

bool BFS(int graph[constant][constant], int source, int destiny, int parent[])
{
	bool visited[constant];
	memset(visited,0,sizeof(visited));

	queue <int> queue;
	queue.push(source);
	visited[source] = true;
	parent[source] = -1;

	while(!queue.empty())
	{
		int vertex = queue.front();
		queue.pop();
		for(int vertex_in = 0; vertex_in<constant; vertex_in ++)
		{
			if(visited[vertex_in] == false && graph[vertex][vertex_in] > 0)
			{
				queue.push(vertex_in);
				parent[vertex_in] = vertex;
				visited[vertex_in] = true;
			}
		}
	}
	return (visited[destiny] == true);
}

int fordFulkerson(int graph[constant][constant], int source, int destiny)
{
	int vertex1, vertex2;
	int graph_in[constant][constant];

	for (vertex1 = 0; vertex1 < constant; vertex1++)
    {
        for (vertex2 = 0; vertex2 < constant; vertex2++)
        {
            graph_in[vertex1][vertex2] = graph[vertex1][vertex2];
        }
    }
	int parent[constant];
	int max_flow = 0;
	while(BFS(graph_in,source,destiny, parent))
	{
		int path_flow = INT_MAX;
		for(vertex2 = destiny; vertex2 != source; vertex2 = parent[vertex2])
		{
			vertex1 = parent[vertex2];
			path_flow = min(path_flow, graph_in[vertex1][vertex2]);
		}
		for(vertex2 = destiny; vertex2 != source; vertex2 = parent[vertex2])
		{
			vertex1 = parent[vertex2];
			graph_in[vertex1][vertex2] -= path_flow;
			graph_in[vertex2][vertex1] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}

int main()
{
	ifstream entrada("graph.in");
	int controll;
	int graph[constant][constant];
	int v1,v2,v3,v4,v5;
	for(controll = 0;controll<constant;controll++)
	{
		entrada >> v1 >> v2 >> v3 >> v4 >> v5;
		graph[controll][0] = {v1};
		graph[controll][1] = {v2};
		graph[controll][2] = {v3};
		graph[controll][3] = {v4};
		graph[controll][4] = {v5};
	}
    printf("\n");
    printf("Ford Fulkerson:\n");
    printf("\n");
    for(controll = 1;controll<constant;controll++)
    {
        printf("Maximum flow between the vertex %d and the source: ",controll);
        cout << fordFulkerson(graph,0,controll);
        printf("\n");
    }
    printf("\n");
}


