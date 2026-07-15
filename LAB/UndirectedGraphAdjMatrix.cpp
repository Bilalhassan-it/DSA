//your required to implement undirected graph using adjacency matrix, now perform the following operations on graph:also take  complete adjacency Matrix as input and validate if adjecency matrix is valid or not .
//find if the Graph is connected or not, Findif graph is completely connected or not; if Graph is connected ;just comment whether it is cyclic or not;
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

static bool isValidUndirectedAdjMatrix(const vector<vector<int>>& a, string &reason) {
    int n = (int)a.size();
    if (n == 0) {
        reason = "Adjacency matrix size must be > 0.";
        return false;
    }
    for (int i = 0; i < n; i++) {
        if ((int)a[i].size() != n) {
            reason = "Adjacency matrix must be square (n x n).";
            return false;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i][i] != 0) {
            reason = "For a simple undirected graph, diagonal entries (a[i][i]) must be 0.";
            return false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(a[i][j] == 0 || a[i][j] == 1)) {
                reason = "Adjacency matrix must contain only 0 or 1 for simple graph.";
                return false;
            }
            if (a[i][j] != a[j][i]) {
                reason = "Adjacency matrix is not symmetric; graph is not undirected.";
                return false;
            }
        }
    }
    return true;
}

static vector<int> bfsReachableFrom(const vector<vector<int>>& a, int src) {
    int n = (int)a.size();
    vector<int> vis(n, 0);
    queue<int> q;
    vis[src] = 1;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (a[u][v] == 1 && !vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return vis;
}

static bool isConnected(const vector<vector<int>>& a) {
    int n = (int)a.size();

    // For a simple undirected graph, pick any vertex with degree > 0.
    int start = -1;
    for (int i = 0; i < n; i++) {
        int deg = 0;
        for (int j = 0; j < n; j++) deg += a[i][j];
        if (deg > 0) {
            start = i;
            break;
        }
    }

    // If no edges exist, graph is not connected (for this assignment-style output).
    if (start == -1) return false;

    vector<int> vis = bfsReachableFrom(a, start);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) return false;
    }
    return true;
}

static bool isCompletelyConnected(const vector<vector<int>>& a) {
    int n = (int)a.size();
    // Complete graph: all off-diagonal entries must be 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (a[i][j] != 0) return false;
            } else {
                if (a[i][j] != 1) return false;
            }
        }
    }
    return true;
}

static bool hasCycleUndirectedSimpleGraph(const vector<vector<int>>& a) {
    int n = (int)a.size();
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        // BFS/DFS with parent tracking; use DFS stack simulation for simplicity.
        stack<pair<int,int>> st;
        st.push({i, -1});
        while (!st.empty()) {
            auto [u, parent] = st.top();
            st.pop();
            if (vis[u]) continue;
            vis[u] = 1;

            for (int v = 0; v < n; v++) {
                if (a[u][v] == 1) {
                    if (!vis[v]) {
                        st.push({v, u});
                    } else if (v != parent) {
                        // Found a back-edge to an already visited node that's not the parent.
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of vertices (n): ";
    if (!(cin >> n)) return 0;

    vector<vector<int>> a(n, vector<int>(n));
    cout << "Enter complete adjacency matrix (0/1) of size " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    string reason;
    if (!isValidUndirectedAdjMatrix(a, reason)) {
        cout << "Invalid adjacency matrix: " << reason << "\n";
        return 0;
    }

    bool connected = isConnected(a);
    bool complete = isCompletelyConnected(a);

    cout << "Graph Connected: " << (connected ? "Yes" : "No") << "\n";
    cout << "Graph Completely Connected (Complete Graph): " << (complete ? "Yes" : "No") << "\n";

    if (connected) {
        bool cyc = hasCycleUndirectedSimpleGraph(a);
        cout << "Since the graph is connected, it is " << (cyc ? "Cyclic" : "Acyclic") << "\n";
    }

    return 0;
}

