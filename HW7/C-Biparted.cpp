// https://zh.wikipedia.org/wiki/二分图#二分性测试
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

enum Status {
    UNVISITED,
    VISITING,
    VISITED,
};

struct Vertice {
    int n;
    Status status = UNVISITED;
    vector<Vertice*> neighbors;
    Vertice* parent;
    bool isA;
};

struct Edge {
    int u, v;
};

void DFS(Vertice* v, bool isA) {
    v->status = VISITING;
    v->isA = isA;
    for (Vertice* neighbor : v->neighbors) {
        if (neighbor->status == UNVISITED) {
            neighbor->parent = v;
            DFS(neighbor, !isA);
        }
    }
    v->status = VISITED;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Vertice> vertices(N);
    vector<Edge> edges(M);
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        vertices[u - 1].n = u;
        vertices[v - 1].n = v;
        vertices[u - 1].neighbors.push_back(&vertices[v - 1]);
        vertices[v - 1].neighbors.push_back(&vertices[u - 1]);
        edges[i - 1] = {u - 1, v - 1};
    }
    DFS(&vertices[0], true);
    for (Edge edge : edges) {
        if (vertices[edge.u].isA == vertices[edge.v].isA) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (Vertice v : vertices) {
        if (v.isA) {
            cout << v.n << " ";
        }
    }
    cout << endl;
    for (Vertice v : vertices) {
        if (!v.isA) {
            cout << v.n << " ";
        }
    }
    cout << endl;
    return 0;
}