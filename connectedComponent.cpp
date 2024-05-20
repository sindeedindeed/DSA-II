#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
bool visited[100];

void dfs(int s) {
    visited[s] = true;
    cout << s << " ";
    for(int i = 0; i < adj[s].size(); i++) {
        if(visited[adj[s][i]] == false) {
            dfs(adj[s][i]);
        }
    }
}

void initialize(int nodes) {
    for(int i = 0; i < nodes; i++) {
        visited[i] = false;
        adj[i].clear();
    }
}

int main() {
    int nodes, edges, u, v, connectComp = 0;
    cin >> nodes >> edges;

    initialize(nodes);

    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < nodes; i++) {
        if(visited[i] == false) {
            dfs(i);
            connectComp++;
            cout << endl;
        }
    }

    cout << "Number of connected components: " << connectComp;
    return 0;
}
