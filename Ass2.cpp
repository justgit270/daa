#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int source, destination, weight;
};

void bellmanFord(vector<Edge> &edges, int V, int E, int source) {
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int weight = edges[i].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    // Print the distance array
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << distance[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges;
    cout << "Enter the source, destination, and weight of each edge:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge temp;
        temp.source = u;
        temp.destination = v;
        temp.weight = w;
        edges.push_back(temp);
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(edges, V, E, source);

    return 0;
}
