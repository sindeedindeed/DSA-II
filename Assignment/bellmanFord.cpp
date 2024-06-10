#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int a, b, cost;
};
int n, m;
vector<Edge> edges;
vector<int> distance;
vector<int> parent;
const int INF = 1e9;

bool BellmanFord(int start){
    distance.assign(n, INF);
    parent.assign(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (const Edge& e : edges) {
            if (distance[e.a] + e.cost < distance[e.b]) {
                distance[e.b] = distance[e.a] + e.cost;
                parent[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO" << endl;
        return false;
    } else {
        int y = x;
        for (int i = 0; i < n; ++i) {
            y = parent[y];
        }

        vector<int> cycle;
        int v = y;
        do {
            cycle.push_back(v + 1);
            v = parent[v];
        } while (v != y);

        cout << "YES" << endl;
        for (int i = cycle.size() - 1; i >= 0; --i) {
            cout << cycle[i] << " ";
            if (cycle[i] == cycle.front()) {
                cout<< cycle.back();
                break;
            }
        }
        cout << endl;
        return true;
    }
}

int main(){
    cin>>n>>m;
    edges.resize(m);
    for (int i = 0; i < m; ++i) {
        cin>>edges[i].a>>edges[i].b>>edges[i].cost;
        edges[i].a--;
        edges[i].b--;
    }
    BellmanFord(0);
    return 0;
}
