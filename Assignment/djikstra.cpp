#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

void dijkstra(int n, vector<vector<pair<int, int>>>& adj, vector<int>& dist, vector<int>& prev) {
    vector<bool> visited(n, false);

    dist[0] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INT_MAX) break;

        visited[u] = true;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back({b - 1, 1});
        adj[b - 1].push_back({a - 1, 1});
    }

    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);

    dijkstra(n, adj, dist, prev);

    if (dist[n - 1] == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        int curr = n - 1;
        while (curr != -1) {
            path.push_back(curr + 1);
            curr = prev[curr];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
