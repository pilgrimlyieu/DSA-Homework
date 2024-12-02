#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum Status {
    UNVISITED,
    VISITING,
    VISITED,
};

struct Vertice {
    int n;
    int distance = -1;
    Status status = UNVISITED;
    vector<Vertice*> neighbors;
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<Vertice> vertices(N);
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        vertices[u - 1].neighbors.push_back(&vertices[v - 1]);
        vertices[v - 1].neighbors.push_back(&vertices[u - 1]);
    }
    Vertice base = vertices[0];
    base.distance = 0;
    base.status = VISITING;
    queue<Vertice*> q;
    q.push(&base);
    while (!q.empty()) {
        Vertice* current = q.front();
        q.pop();
        current->status = VISITED;
        for (Vertice* neighbor : current->neighbors) {
            if (neighbor->status == UNVISITED) {
                neighbor->status = VISITING;
                neighbor->distance = current->distance + 1;
                q.push(neighbor);
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        cout << vertices[i - 1].distance << " ";
    }
    cout << endl;
    return 0;
}