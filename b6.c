#include <stdio.h>

void addEdge(int graph[][100], int u, int v, int isDirected) {
    graph[u][v] = 1;
    if (!isDirected) {
        graph[v][u] = 1;
    }
}

int findMaxDegree(int graph[][100], int vertices, int isDirected) {
    int degrees[vertices];
    for (int i = 0; i < vertices; i++) {
        degrees[i] = 0;
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j]) {
                if (isDirected) {
                    degrees[i]++; 
                    degrees[j]++; 
                } else {
                    degrees[i]++;
                }
            }
        }
    }

    int maxDegree = degrees[0];
    int maxVertex = 0;
    for (int i = 1; i < vertices; i++) {
        if (degrees[i] > maxDegree) {
            maxDegree = degrees[i];
            maxVertex = i;
        }
    }
    return maxVertex;
}

int main() {
    int vertices, edges, isDirected;

    scanf("%d %d %d", &vertices, &edges, &isDirected);

    int graph[100][100] = {0};
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v, isDirected);
    }

    int maxVertex = findMaxDegree(graph, vertices, isDirected);
    printf("%d\n", maxVertex);

    return 0;
}
