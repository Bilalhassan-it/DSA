//make adjency list  add vertex,add edge,  find degree of BFS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
struct vertex{
    int data;
    vector<vertex> edgelist;


}
void BFS(vertex start){
    queue<vertex> q;
    vector<bool> visited(100, false); // Assuming a maximum of 100 vertices
    q.push(start);
    visited[start.data] = true;

    while (!q.empty()) {
        vertex current = q.front();
        q.pop();
        cout << current.data << " ";

        for (vertex neighbor : current.edgelist) {
            if (!visited[neighbor.data]) {
                visited[neighbor.data] = true;
                q.push(neighbor);
            }
        }
    }

 void addvertex(){
    vertex v;
    v.data = data;
    v.edgelist = edgelist;
    }
    void addedge(vertex v1,vertex v2){
    v1.edgelist.push_back(v2);
    v2.edgelist.push_back(v1);
    }
int main(){
    vector<vertex> graph;
    addvertex();
    addvertex();
    addvertex();
    addedge(graph[0],graph[1]);
    addedge(graph[1],graph[2]);
    addedge(graph[0],graph[2]);

   // system("pause");
    return 0;
}   
 