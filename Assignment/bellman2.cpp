#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int from, to, weight;
};

vector<int> bellmanFord(int n, int m, vector<Edge>& edges) {
    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);

    dist[1] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[edge.from] + edge.weight;
                parent[edge.to] = edge.from;
            }
        }
    }

    vector<int> cycle;
    for (const auto& edge : edges) {
        if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.weight < dist[edge.to]) {
            int node = edge.from;
            while (node != edge.to) {
                cycle.push_back(node);
                node = parent[node];
                if (node == -1) break;
            }
            cycle.push_back(edge.to);
            reverse(cycle.begin(), cycle.end());
            return cycle;
        }
    }

    return {};
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    vector<int> cycle = bellmanFord(n, m, edges);

    if (cycle.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int start = *min_element(cycle.begin(), cycle.end());
        auto start_it = find(cycle.begin(), cycle.end(), start);
        for (auto it = start_it; it != cycle.end(); ++it) {
            cout << *it << " ";
        }
        for (auto it = cycle.begin(); it != start_it; ++it) {
            cout << *it << " ";
        }
        cout << start;
        cout << endl;
    }

    return 0;
}