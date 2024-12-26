#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int id;
    int dis = INT_MAX;
};

struct Edge {
    int u;
    int v;
    int w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

bool BellmanFord(vector<Node *> &nodes, vector<Edge *> &edges, int s) {
    nodes[s - 1]->dis = 0;
    for (int i = 0; i < nodes.size() - 1; i++) {
        for (Edge *edge : edges) {
            if (nodes[edge->u - 1]->dis != INT_MAX && // 溢出……
                nodes[edge->v - 1]->dis > nodes[edge->u - 1]->dis + edge->w) {
                nodes[edge->v - 1]->dis = nodes[edge->u - 1]->dis + edge->w;
            }
        }
    }
    for (Edge *edge : edges) {
        if (nodes[edge->v - 1]->dis > nodes[edge->u - 1]->dis + edge->w) {
            return true;
        }
    }
    return false;
}

int main() {
    int F;
    cin >> F;
    for (int i = 0; i < F; i++) {
        int N, M, W;
        cin >> N >> M >> W;
        vector<Node *> nodes;
        vector<Edge *> edges;
        for (int j = 0; j < N; j++) {
            Node *node = new Node();
            node->id = j + 1;
            nodes.push_back(node);
        }
        for (int j = 0; j < M; j++) {
            int S, E, T;
            cin >> S >> E >> T;
            Edge *edge1 = new Edge(S, E, T);
            Edge *edge2 = new Edge(E, S, T);
            edges.push_back(edge1);
            edges.push_back(edge2);
        }
        for (int j = 0; j < W; j++) {
            int S, E, T;
            cin >> S >> E >> T;
            Edge *edge = new Edge(S, E, -T);
            edges.push_back(edge);
        }
        cout << (BellmanFord(nodes, edges, 1) ? "YES" : "NO") << endl;
    }
    return 0;
}
