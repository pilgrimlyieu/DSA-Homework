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
};

void DFS(Vertice& u) {
    u.status = VISITING;
    for (Vertice* v : u.neighbors) {
        if (v->status == UNVISITED) {
            DFS(*v);
        } else if (v->status == VISITING) {
            cout << "YES" << endl;
            exit(0);
        }
    }
    u.status = VISITED;
}

void DFS(vector<Vertice>& vertices) {
    for (Vertice& u : vertices) {
        if (u.status == UNVISITED) {
            DFS(u);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Vertice> vertices(N);
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        vertices[a - 1].neighbors.push_back(&vertices[b - 1]);
    }
    DFS(vertices);
    cout << "NO" << endl;
    return 0;
}