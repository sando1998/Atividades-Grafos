#include<bits/stdc++.h>
# define INF 0x3f3f3f3f
using namespace std;

typedef pair<int, int> Pair;
class Graph
{
    int vertex;
    list<pair<int,int>> *adj;

public:
    Graph(int vertex);
    void addEdge(int vertex1, int vertex2, int weight);
    void Dijkstra(int source);
};

Graph::Graph(int vertex)
{
    this->vertex = vertex;
    adj = new list<Pair> [vertex];
}
void Graph::addEdge(int vertex1, int vertex2, int weight)
{
    adj[vertex1].push_back(make_pair(vertex2, weight));
}
void Graph::Dijkstra(int source)
{
    priority_queue<Pair,vector<Pair>,greater<Pair>> priority_queue;
    vector<int> distance(vertex,INF);

    priority_queue.push(make_pair(0,source));
    distance[source] = 0;

    while(!priority_queue.empty())
    {
        int vertex_1 = priority_queue.top().second;
        priority_queue.pop();

        list<pair<int,int>>::iterator i;
        for(i = adj[vertex_1].begin(); i!= adj[vertex_1].end() ;++i)
        {
            int vertex_2 = (*i).first;
            int weight = (*i).second;

            if(distance[vertex_2] > distance[vertex_1] + weight)
            {
                distance[vertex_2] = distance[vertex_1] + weight;
                priority_queue.push(make_pair(distance[vertex_2],vertex_2));
            }
        }
    }
    for(int i = 0; i < vertex; ++ i)
    {
        printf("Shortest distance from vertex %d to vertex source = %d\n",i,distance[i]);
    }  
}

int main()
{
    int vertex1,vertex2,weight;
    int vertex,edges;
    int controll;
        
    ifstream input("graph.in");//catch the graph
    input >> vertex >> edges;//catch the number of vertex and edges
    Graph graph(vertex);//create the graph
    vector<Pair> adj[vertex];

    for(controll=0;controll<edges;controll++)//fills the graph
    {
        input >> vertex1 >> vertex2 >> weight;
        graph.addEdge(vertex1,vertex2,weight);
    }
    printf("\n");
    printf("Dijkstra algorithm:\n");
    printf("\n");
    graph.Dijkstra(0);//run the Dijkstra algorithm
    printf("\n");
}