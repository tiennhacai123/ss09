#include <stdio.h>
#include <limits.h>

#define V 100 

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src, int n) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < n; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, n);
}

int main() {
    int graph[V][V] = {
        {0, 10, 5, 0},
        {10, 0, 2, 0},
        {5, 2, 0, 1},
        {0, 0, 1, 0}
    };
    int src = 0;
    int n = 4;

    dijkstra(graph, src, n);


    return 0;
}