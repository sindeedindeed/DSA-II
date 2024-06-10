#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent, level;
};
class Graph {
    int V;
    vector<Edge> edges;
public:
    Graph(int n) {
        V = n;
    }
void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }
void printMST(vector<Edge> result) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
        }
    }

    bool compareEdges(Edge a, Edge b) {
        return a.weight < b.weight;
    }

    int findRoot(vector<Subset> &subsets, int i) {
        if (subsets[i].parent != i) {
            subsets[i].parent = findRoot(subsets, subsets[i].parent);
        }
        return subsets[i].parent;
    }

    void Union(vector<Subset> &subsets, int x, int y) {
        int xroot = findRoot(subsets, x);
        int yroot = findRoot(subsets, y);
        if (subsets[xroot].level < subsets[yroot].level) {
            subsets[xroot].parent = yroot;
        }
        else if (subsets[yroot].level < subsets[xroot].level) {
            subsets[yroot].parent = xroot;
        }
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].level++;
        }
    }

    void kruskal() {
        vector<Edge> result;
        sort(edges.begin(), edges.end(), [this](Edge a, Edge b) { return compareEdges(a, b); });
        vector<Subset> subsets(V);
        for (int i = 0; i < V; i++) {
            subsets[i].parent = i;
            subsets[i].level = 0;
        }
        for (int i = 0; result.size() < V - 1 && i < edges.size(); i++) {
            Edge currEdge = edges[i];
            int x = findRoot(subsets, currEdge.src);
            int y = findRoot(subsets, currEdge.dest);
            if (x != y) {
                result.push_back(currEdge);
                Union(subsets, x, y);
            }
        }
        printMST(result);
    }
};

int main() {
    int V = 4;
    Graph graph(V);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15); // Changed one of the edges to avoid duplicate edge
    graph.addEdge(2, 3, 4);
    graph.kruskal();
    return 0;
}
