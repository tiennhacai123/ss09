#include <stdio.h>
#define V 4
// V la so dinh

void addEdge(int matrix[V][V], int i, int j){
    matrix[i][j] = 1; 
    matrix[j][i] = 1;
}

void printMaxtrix(int matrix[V][V]){
    for(int i = 0;i < V; i++){
        for(int j = 0; j < V; j++){
            printf("%d \t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int matrix[V][V] = {0};
    addEdge(matrix, 0, 1);
    addEdge(matrix, 0, 2);
    addEdge(matrix, 0, 3);
    addEdge(matrix, 0, 4);
    // int matrix[V][V] = {{0,1,0,0}, {1,0,1,0},{0,1,0,1}, {0,0,1,0}}
    printMaxtrix(matrix);
    return 0;
}