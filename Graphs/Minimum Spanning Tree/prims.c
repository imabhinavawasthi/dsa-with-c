// Prim's Algorithm in C

#include<stdio.h>
#include<stdbool.h> 
#include<string.h>

#define INF 9999999

// number of vertices in graph
#define V 5

// create a 2d array of size 5x5
//for adjacency matrix to represent graph
int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}};

int main() {
  int no_edge;

  int visited[V];
  memset(visited, 0, sizeof(visited));
  
  // set number of edge to 0
  no_edge = 0;

  visited[0] = true;

  int x;
  int y;

  int minWeight = 0;

  while (no_edge < V - 1) {// (v-1) times

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (visited[i]==1) { // if i is visited
        for (int j = 0; j < V; j++) {
          if (visited[j]==0 && G[i][j]!=0) {  // not in visited and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    visited[y] = true;
    no_edge++;
    minWeight+=G[x][y];
  }

  printf("Minimum Weight: %d",minWeight);

  return 0;
}