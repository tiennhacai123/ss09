#include <stdio.h>
#define V 10 

void nhapSoluong(int *n, int *m) {
    printf("Nhap so luong dinh: ");
    scanf("%d", n);
    printf("Nhap so luong canh: ");
    scanf("%d", m);
}

void insertEdge(int m, int edges[m][2]) {
    printf("Nhap danh sach cac canh (vd: 0 1):\n");
    for (int i = 0; i < m; i++) {
        printf("Canh %d: ", i + 1);
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        edges[i][0]--; 
        edges[i][1]--; 
    }
}

void addEdge(int matrix[V][V], int i, int j) {
    matrix[i][j] = 1;
    matrix[j][i] = 1;  
}

void printMatrix(int n, int matrix[V][V]) {
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d    ", matrix[i][j]);
        }
        printf("\n");
    }
}

int checkSymmetry(int n, int matrix[V][V]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0; 
            }
        }
    }
    return 1;  
}

int main() {
    int n, m;
    printf("Nhap so luong dinh va canh\n");
    
    nhapSoluong(&n, &m);  
    
    int edges[m][2];
    int matrix[V][V] = {0}; 
    
    insertEdge(m, edges);  
    
    for (int i = 0; i < m; i++) {
        addEdge(matrix, edges[i][0], edges[i][1]); 
    }
    
    printMatrix(n, matrix);  
    
    if (checkSymmetry(n, matrix)) {
        printf("Ma tran ke la doi xung.\n");
    } else {
        printf("Ma tran ke khong doi xung.\n");
    }
    
    return 0;
}
