// ref: Prim algorithm
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

struct Vertice {
    int i;
    Vertice(int index) : i(index) {}
};

struct Edge {
    Vertice *u;
    Vertice *v;
    int weight;
    Edge(Vertice *u, Vertice *v, int w) : u(u), v(v), weight(w) {}
    bool operator<(const Edge &e) const {
        return weight > e.weight;
    }
};

int MST(int n, vector<Vertice *> vertices, vector<Edge> &edges) {
    int sum = 0;
    unordered_set<int> visited;
    priority_queue<Edge> pq;
    visited.insert(0);
    for (const Edge &edge : edges) {
        if (edge.u->i == 0 || edge.v->i == 0) {
            pq.push(edge);
        }
    }
    while (visited.size() < n && !pq.empty()) {
        Edge e = pq.top();
        pq.pop();
        if (visited.find(e.u->i) != visited.end() && visited.find(e.v->i) != visited.end()) {
            continue;
        }
        sum += e.weight;
        int newVertice = visited.find(e.u->i) == visited.end() ? e.u->i : e.v->i;
        visited.insert(newVertice);
        for (const Edge &edge : edges) {
            if (edge.u->i == newVertice || edge.v->i == newVertice) {
                pq.push(edge);
            }
        }
    }
    return sum;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Vertice *> vertices(N, nullptr);
    vector<Edge> edges;
    for (int i = 0; i < N; i++) {
        vertices[i] = new Vertice(i);
    }
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(vertices[u], vertices[v], w));
    }
    cout << MST(N, vertices, edges) << endl;
    return 0;
}
