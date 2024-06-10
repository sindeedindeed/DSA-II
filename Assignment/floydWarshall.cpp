#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const long long INF = 1e9;


int main() {
    int numNodes, numEdges, numQueries;
    cin >> numNodes >> numEdges >> numQueries;

    vector<vector<long long>> distances(numNodes + 1, vector<long long>(numNodes + 1, LLONG_MAX));

    for (int i = 1; i <= numNodes; ++i) {
        distances[i][i] = 0;
    }

    for (int i = 0; i < numEdges; ++i) {
        int node1, node2;
        long long weight;
        cin >> node1 >> node2 >> weight;
        distances[node1][node2] = min(distances[node1][node2], weight);
        distances[node2][node1] = min(distances[node2][node1], weight);
    }

    for (int k = 1; k <= numNodes; ++k) {
        for (int i = 1; i <= numNodes; ++i) {
            for (int j = 1; j <= numNodes; ++j) {
                if (distances[i][k] < LLONG_MAX && distances[k][j] < LLONG_MAX) {
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < numQueries; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        if (distances[node1][node2] == LLONG_MAX) {
            cout << -1 << endl;
        } else {
            cout << distances[node1][node2] << endl;
        }
    }

    return 0;
}

