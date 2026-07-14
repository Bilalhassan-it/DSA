//using matrix to represent graph and implementing breadth first search 
//vertex,edge,degree,path,cycle,connected component,tree,forest,adjacency matrix, adjacency list,incidence matrix
#include<iostream>
using namespace std;

int main(){
    int graph[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };
    int visited[5] = {0};
    int queue[5];
    int front = -1;
    int rear = -1;

    // BFS starting from vertex 0
    visited[0] = 1;
    queue[++rear] = 0;

    cout << "BFS Traversal: ";
    while (front != rear) {
        int currentVertex = queue[++front];
        cout << currentVertex << " ";

        for (int i = 0; i < 5; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

   // system("pause");
    return 0;
}
