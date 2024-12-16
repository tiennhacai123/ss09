#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;               
    struct Node* next;      
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjList[], int i, int j) {
    Node* newNode = createNode(j);
    newNode->next = adjList[i];
    adjList[i] = newNode;

    newNode = createNode(i);
    newNode->next = adjList[j];
    adjList[j] = newNode;
}

void printAdjList(Node* adjList[], int vertices) {
    for (int i = 0; i < vertices; i++) {
        Node* temp = adjList[i];
        printf("Đỉnh %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int dfsCycleCheck(Node* adjList[], int current, int visited[], int parent) {
    visited[current] = 1;

    Node* temp = adjList[current];
    while (temp != NULL) {
        int adjacent = temp->data;

        if (!visited[adjacent]) {
            if (dfsCycleCheck(adjList, adjacent, visited, current))
                return 1;
        }
        else if (adjacent != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}
int hasCycle(Node* adjList[], int vertices) {
    int visited[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (dfsCycleCheck(adjList, i, visited, -1))
                return 1;
        }
    }
    return 0; 
}

int main() {
    int vertices = 4; 
    Node* adjList[vertices]; 
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }
    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 0);
    printAdjList(adjList, vertices);
    if (hasCycle(adjList, vertices)) {
        printf("Đồ thị có chu kỳ\n");
    } else {
        printf("Đồ thị không có chu kỳ\n");
    }

    return 0;
}
