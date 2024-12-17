#include <iostream>
#include <vector>

using namespace std;

enum Status {
    UNVISITED,
    VISITING,
    VISITED,
};

struct Vertice {
    int n;
    Status status = UNVISITED;
    vector<Vertice *> neighbors;
};

void DFS(Vertice &u, vector<Vertice> &topological) {
    u.status = VISITING;
    for (Vertice *v : u.neighbors) {
        if (v->status == UNVISITED) {
            DFS(*v, topological);
        } else if (v->status == VISITING) {
            cout << "YES" << endl;
            exit(0);
        }
    }
    u.status = VISITED;
    topological.push_back(u);
}

void DFS(vector<Vertice> &vertices, vector<Vertice> &topological) {
    for (Vertice &u : vertices) {
        if (u.status == UNVISITED) {
            DFS(u, topological);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Vertice> vertices(N);
    vector<Vertice> topological = {};
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        vertices[u - 1].n = u;
        vertices[v - 1].n = v;
        vertices[u - 1].neighbors.push_back(&vertices[v - 1]);
    }
    DFS(vertices, topological);
    cout << "NO" << endl;
    for (int i = topological.size() - 1; i >= 0; i--) {
        cout << topological[i].n << " ";
    }
    cout << endl;
    return 0;
}