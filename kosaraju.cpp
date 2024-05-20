#include <bits/stdc++.h>
#define MAX_N 20001
#define ll long long int
using namespace std;

int n, m;

struct Node {
    vector<int> adj;
    vector<int> rev_adj;
};

Node g[MAX_N];

stack<int> S;
bool visited[MAX_N];

void dfs_1(int x) {
    visited[x] = true;
    for (int i = 0; i < g[x].adj.size(); i++) {
        if (!visited[g[x].adj[i]]) dfs_1(g[x].adj[i]);
    }
    S.push(x);
}

void dfs_2(int x) {
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < g[x].rev_adj.size(); i++) {
        if (!visited[g[x].rev_adj[i]]) dfs_2(g[x].rev_adj[i]);
    }
}

void Kosaraju() {
    // Step 1: Perform DFS and push finished vertices onto stack
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs_1(i);
    }

    // Step 2: Reset visited array
    fill(visited, visited + n, false);

    // Step 3: Process all vertices in order defined by stack
    int compNum = 1; // Start component numbering from 1
    while (!S.empty()) {
        int v = S.top();
        S.pop();
        if (!visited[v]) {
            cout << "Component " << compNum << ": ";
            dfs_2(v);
            compNum++;
            cout << endl;
        }
    }
}

int main() {
    cin >> n >> m;
    int a, b;
    while (m--) {
        cin >> a >> b;
        g[a].adj.push_back(b);
        g[b].rev_adj.push_back(a);
    }

    Kosaraju();

    return 0;
}
