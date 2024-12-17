#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

struct Vertice {
    bool active = true;
    vector<Vertice *> neighbors = {};
    int degree() {
        int count = 0;
        for (Vertice *v : neighbors) {
            if (v->active) {
                count++;
            }
        }
        return count;
    }
};

int minHeight(int n, vector<Vertice *> vertices, vector<pair<Vertice *, Vertice *>> &edges) {
    queue<Vertice *> leaves;
    for (Vertice *v : vertices) {
        if (v->degree() == 1) {
            leaves.push(v);
        }
    }
    int remaining = n;
    int height = 0;
    while (remaining >= 2) {
        int size = leaves.size();
        remaining -= size;
        height++;
        for (int i = 0; i < size; i++) {
            Vertice *leaf = leaves.front();
            leaves.pop();
            leaf->active = false;
            for (Vertice *neighbor : leaf->neighbors) {
                if (neighbor->active && neighbor->degree() == 1) {
                    leaves.push(neighbor);
                }
            }
        }
    }
    return height;
}

int main() {
    int N;
    cin >> N;
    vector<Vertice *> vertices(N, nullptr);
    vector<pair<Vertice *, Vertice *>> edges;
    int ui, vi;
    while (cin >> ui >> vi) {
        if (vertices[ui] == nullptr) {
            vertices[ui] = new Vertice();
        }
        if (vertices[vi] == nullptr) {
            vertices[vi] = new Vertice();
        }
        vertices[ui]->neighbors.push_back(vertices[vi]);
        vertices[vi]->neighbors.push_back(vertices[ui]);
        edges.push_back({vertices[ui], vertices[vi]});
    }
    int height = minHeight(N, vertices, edges);
    cout << height << endl;
    return 0;
}