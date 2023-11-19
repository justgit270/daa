#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// Function to find the minimum edge cost
int leastCost(vector<vector <int> > &graph, int n, int s, int t) {
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (i != t && graph[s][i] < min) {
            min = graph[s][i];
        }
    }
    return min;
}

// Function to find the second minimum edge cost
int secondLeastCost(vector<vector <int> > &graph, int n, int s, int t) {
    int firstMin = INT_MAX, secondMin = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (i != t && graph[s][i] < firstMin) {
            secondMin = firstMin;
            firstMin = graph[s][i];
        } else if (i != t && graph[s][i] < secondMin && graph[s][i] != firstMin) {
            secondMin = graph[s][i];
        }
    }
    return secondMin;
}

// Function to find the minimum cost of traversal
void TSP(vector<vector <int> > &graph, int n) {
    vector<int> vertex;
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            vertex.push_back(i);
        }
    }

    int minPath = INT_MAX;
    do {
        int currentPathWeight = 0;
        int k = 0;
        for (int i = 0; i < vertex.size(); i++) {
            currentPathWeight += graph[k][vertex[i]];
            k = vertex[i];
        }
        currentPathWeight += graph[k][0];

        minPath = min(minPath, currentPathWeight);
    } while (next_permutation(vertex.begin(), vertex.end()));

    cout << "Minimum cost : " << minPath << endl;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector <int> > graph(n, vector<int>(n, 0));
    cout << "Enter the cost matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    TSP(graph, n);
    return 0;
}
