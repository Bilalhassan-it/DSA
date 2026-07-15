#include <iostream>
using namespace std;

const int MAX = 20;

int graph[MAX][MAX];
bool visited[MAX];
int n;

// DFS for Connected Graph
void DFS(int v)
{
    visited[v] = true;

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

// DFS for Cycle Detection
bool DFS_Cycle(int v, int parent)
{
    visited[v] = true;

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1)
        {
            if (!visited[i])
            {
                if (DFS_Cycle(i, v))
                    return true;
            }
            else if (i != parent)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter Adjacency Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    // Validate Matrix
    bool valid = true;

    for (int i = 0; i < n; i++)
    {
        if (graph[i][i] != 0)
            valid = false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] != graph[j][i])
                valid = false;
        }
    }

    if (!valid)
    {
        cout << "\nInvalid Adjacency Matrix";
        return 0;
    }

    cout << "\nValid Adjacency Matrix\n";

    // Check Connected
    for (int i = 0; i < n; i++)
        visited[i] = false;

    DFS(0);

    bool connected = true;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            connected = false;
    }

    if (!connected)
    {
        cout << "Graph is NOT Connected";
        return 0;
    }

    cout << "Graph is Connected\n";

    // Check Complete Graph
    bool complete = true;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
                count++;
        }

        if (count != n - 1)
            complete = false;
    }

    if (complete)
        cout << "Graph is Completely Connected\n";
    else
        cout << "Graph is NOT Completely Connected\n";

    // Check Cycle
    for (int i = 0; i < n; i++)
        visited[i] = false;

    if (DFS_Cycle(0, -1))
        cout << "Graph is Cyclic";
    else
        cout << "Graph is Acyclic";

    return 0;
}