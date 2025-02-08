#include <stdio.h>
#include <limits.h>

#define N 4  // Number of cities

// Adjacency matrix representation of graph
int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[N]; // Track visited cities
int minCost = INT_MAX; // Store the minimum cost

// Function to find the shortest route using backtracking
void tsp(int city, int count, int cost, int start) {
    if (count == N && graph[city][start] > 0) { // All cities visited, return to start
        cost+=graph[city][start];
        if (cost < minCost) {
            minCost = cost;
        }
        return;
    }

    // recursion
    for (int i = 0; i < N; i++) {
        if (!visited[i] && graph[city][i] > 0) { // Visit unvisited cities
            visited[i] = 1;
            tsp(i, count + 1, cost + graph[city][i], start);
            visited[i] = 0; // Backtrack
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    visited[0] = 1; // Start from city 0
    tsp(0, 1, 0, 0);

    printf("Minimum cost of TSP: %d\n", minCost);
    return 0;
}
