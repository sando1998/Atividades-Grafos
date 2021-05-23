#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int source,destiny,weight;
};
struct Graph
{
    int vertex,edges;
    struct Edge* edge;
};

struct Graph* createGraph(int vertex,int edges)
{
    struct Graph* graph = new Graph;

    graph -> vertex = vertex;
    graph -> edges = edges;
    graph -> edge = new Edge[edges];

    return graph;
}
void print(int distances[],int vertex)
{
    for(int i = 0;i<vertex; ++ i)
    {
        printf("Distance from vertex %d to vertex source = %d\n",i,distances[i]);
    }    
}

void BellmanFord(struct Graph* graph, int source)
{
    int vertex = graph -> vertex;
    int edges = graph -> edges;
    int distance[vertex];
    
    for (int i = 0; i< vertex; i++)
    {
        distance[i] = INT_MAX;        
    }
    distance[source] = 0;

    for (int i = 1; i <= vertex - 1; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int vertex_1 = graph -> edge[j].source;
            int vertex_2 = graph -> edge[j].destiny;
            int weight = graph -> edge[j].weight;
            if (distance[vertex_1] != INT_MAX && distance[vertex_1] + weight < distance[vertex_2])
            {
                distance[vertex_2] = distance[vertex_1] + weight;
            }      
        }
    }

    for(int i = 0; i < edges; i ++)
    {
        int vertex_1 = graph -> edge[i].source;
        int vertex_2 = graph -> edge[i].destiny;
        int weight = graph -> edge[i].weight;

        if (distance[vertex_1] != INT_MAX && distance[vertex_1] + weight < distance[vertex_2])
        {
            printf("The graph has a negative cycle");
            return;
        }
    }
    print(distance,vertex);
    return;
}

int main()
{
    int vertex,edges;
    int vertex1,vertex2,weight;
    int controll;
    
    ifstream input("graph.in");//catch the graph
    input >> vertex >> edges;//catch the number of vertex and edges
    struct Graph* graph = createGraph(vertex, edges);//create the graph
    for(controll=0;controll<edges;controll++)//fills the graph
    {
        input >> vertex1 >> vertex2 >> weight;
        graph -> edge[controll].source = vertex1;
        graph -> edge[controll].destiny = vertex2;
        graph -> edge[controll].weight = weight;
    }
    printf("\n");
    printf("Bellman Ford algorithm:\n");
    printf("\n");
    BellmanFord(graph,0);//run Bellman Ford algorithm
    printf("\n");
}