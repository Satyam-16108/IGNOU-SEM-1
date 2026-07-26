#include <bits/stdc++.h>
using namespace std;
#define V 5
#define INF 99999

void floydWarshall(int graph[][V]) {
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) cout << "INF\t";
            else cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int graph[V][V] = { 
        {0, 4, INF, INF, -5},
        {INF, 0, 5, INF, INF},
        {INF, INF, 0, -6, INF},
        {INF, 2, INF, 0, 6},
        {INF, 8, INF, INF, 0}
    };
    floydWarshall(graph);
    return 0;
}
