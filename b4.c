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

void addEdge(Node* adjList[], int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void printAdjList(Node* adjList[], int vertices) {
    printf("Danh sách kề của đồ thị:\n");
    for (int i = 0; i < vertices; i++) {
        printf("Đỉnh %d: ", i);
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void BFS(Node* adjList[], int start, int vertices) {
    int visited[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;  
    }

    int queue[vertices];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;
    printf("Thứ tự các đỉnh được duyệt BFS từ đỉnh %d: ", start);
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        Node* temp = adjList[current];
        while (temp != NULL) {
            int adjacent = temp->data;
            if (!visited[adjacent]) {
                visited[adjacent] = 1;         
                queue[rear++] = adjacent;     
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges;
    printf("Nhập số đỉnh: ");
    scanf("%d", &vertices);

    printf("Nhập số cạnh: ");
    scanf("%d", &edges);
    Node* adjList[vertices];
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }
    printf("Nhập các cạnh (đỉnh1 đỉnh2):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adjList, u, v);
    }
    printAdjList(adjList, vertices);
    int startVertex;
    printf("Nhập đỉnh bắt đầu duyệt BFS: ");
    scanf("%d", &startVertex);
    BFS(adjList, startVertex, vertices);

    return 0;
}
