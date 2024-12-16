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

void addEdge(Node* arr[], int i, int j) {
    Node* newNode = createNode(j);
    newNode->next = arr[i];
    arr[i] = newNode;

    newNode = createNode(i);
    newNode->next = arr[j];
    arr[j] = newNode;
}

// In ra danh sách kề của mỗi đỉnh
void printList(Node* arr[], int V) {
    for (int i = 0; i < V; i++) {
        Node* temp = arr[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 4; // Số lượng đỉnh
    Node* adj[V];

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    printList(adj, V);

    return 0;
}