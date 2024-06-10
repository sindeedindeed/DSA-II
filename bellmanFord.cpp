#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

vector<int> bellmanFord(int n, int m, vector<Edge>& edges) {
    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);

    dist[1] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
                parent[edge.v] = edge.u;
            }
        }
    }

    int cycle_start = -1;
    for (const auto& edge : edges) {
        if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.w < dist[edge.v]) {
            cycle_start = edge.v;
            for (int i = 0; i < n; ++i) {
                cycle_start = parent[cycle_start];
            }
            break;
        }
    }

    if (cycle_start == -1) {
        return {};
    }

    vector<int> cycle;
    for (int cur = cycle_start;; cur = parent[cur]) {
        cycle.push_back(cur);
        if (cur == cycle_start && cycle.size() > 1) {
            break;
        }
    }
    reverse(cycle.begin(), cycle.end());
    return cycle;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<int> cycle = bellmanFord(n, m, edges);

    if (cycle.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int node : cycle) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
