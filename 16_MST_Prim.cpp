#include <bits/stdc++.h>
using namespace std;
#define V 10 

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primMST(int graph[V][V]) {
    int parent[V], key[V];    
    bool mstSet[V];
    for (int i = 0; i < V; i++) key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0; 
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << "V" << parent[i]+1 << " - V" << i+1 << " \t" << graph[i][parent[i]] << " \n";
}

int main() {
    int graph[V][V] = {0}; 
    graph[0][1] = 35; graph[1][0] = 35;
    graph[0][3] = 20; graph[3][0] = 20;
    cout << "Prim's MST function structured and ready. Fill full adjacency matrix to test." << endl;
    return 0;
}
