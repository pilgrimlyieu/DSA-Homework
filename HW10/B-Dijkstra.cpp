#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int i;
    int dis = INT_MAX;
    bool operator<(const Node &n) const {
        return dis > n.dis;
    }
};

struct Edge {
    int u;
    int v;
    int w;
};

void Dijkstra(vector<Node *> &nodes, vector<Edge *> &edges, int s) {
    priority_queue<Node> pq;
    nodes[s]->dis = 0;
    pq.push(*nodes[s]);
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        for (Edge *edge : edges) {
            if (edge->u == node.i) {
                if (nodes[edge->v]->dis > node.dis + edge->w) {
                    nodes[edge->v]->dis = node.dis + edge->w;
                    pq.push(*nodes[edge->v]);
                }
            } else if (edge->v == node.i) {
                if (nodes[edge->u]->dis > node.dis + edge->w) {
                    nodes[edge->u]->dis = node.dis + edge->w;
                    pq.push(*nodes[edge->u]);
                }
            }
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<Node *> nodes;
    vector<Edge *> edges;
    for (int i = 0; i < n; i++) {
        Node *node = new Node();
        node->i = i;
        nodes.push_back(node);
    }
    for (int i = 0; i < m; i++) {
        Edge *edge = new Edge();
        cin >> edge->u >> edge->v >> edge->w;
        edges.push_back(edge);
    }
    Dijkstra(nodes, edges, s);
    cout << nodes[t]->dis << endl;
    return 0;
}