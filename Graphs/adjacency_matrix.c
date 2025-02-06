// Adjacency Matrix representation in C

#include <stdio.h>
#define V 6

// Initialize the matrix to zero
void init(int arr[][V]) {
  int i, j;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      arr[i][j] = -1;
}

// Add edges
void addEdge(int arr[][V], int i, int j, int w) {
  arr[i][j] = w;
  arr[j][i] = w;
}

// Print the matrix
void printAdjMatrix(int arr[][V]) {
  int i, j;

  for (i = 0; i < V; i++) {
    printf("%d: ", i);
    for (j = 0; j < V; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int adjMatrix[V][V];

  init(adjMatrix);
  addEdge(adjMatrix, 0, 5, 7);
  addEdge(adjMatrix, 0, 1, 8);
  addEdge(adjMatrix, 1, 2, 3);
  addEdge(adjMatrix, 2, 5, 2);
  addEdge(adjMatrix, 1, 3, 5);
  addEdge(adjMatrix, 2, 3, 9);
  addEdge(adjMatrix, 2, 4, 2);
  addEdge(adjMatrix, 3, 4, 1);

  printAdjMatrix(adjMatrix);

  return 0;
}