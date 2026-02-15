// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int V = 5;
    int E = 6;
    int edges[6][2] = {
        {1,2},
        {1,4},
        {0,4},
        {2,3},
        {1,3},
        {2,4}
    };
    
    int matrix[V][V] = {0};
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            matrix[i][j] = 0;
        }
    }
    for(int i = 0;i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        matrix[u][v] = 1;
        matrix[v][u] = 1; // for undirected graph
    }
    
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}