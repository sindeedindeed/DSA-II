#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topSort(vector<vector<int>>& graph, vector<int>& indegree) {
    int n = graph.size();
    vector<int> order;
    queue<int> q;
    
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0)
            q.push(i);
    }
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        
        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    
    if (order.size() != n)
        order.clear();
    
    return order;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        indegree[b - 1]++;
    }
    
    vector<int> order = topSort(graph, indegree);
    
    if (order.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int course : order) {
            cout << course + 1 << " ";
        }
        cout << endl;
    }
    
    return 0;
}
