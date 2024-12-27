// ref:
// https://leetcode.cn/problems/sum-of-distances-in-tree/solutions/2345592/tu-jie-yi-zhang-tu-miao-dong-huan-gen-dp-6bgb/
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int id;
};

struct Edge {
    int u, v;
};

void dfs(vector<int> &ans, vector<int> &size, vector<Edge> &edges, int u, int fa, int depth) {
    ans[0] += depth;
    for (auto edge : edges) {
        if (edge.u == u && edge.v != fa) {
            dfs(ans, size, edges, edge.v, u, depth + 1);
            size[u] += size[edge.v];
        } else if (edge.v == u && edge.u != fa) {
            dfs(ans, size, edges, edge.u, u, depth + 1);
            size[u] += size[edge.u];
        }
    }
}

void solve(vector<int> &ans, vector<int> &size, vector<Edge> &edges, int u, int fa, int n) {
    for (auto edge : edges) {
        if (edge.u == u && edge.v != fa) {
            ans[edge.v] = ans[u] + n - 2 * size[edge.v];
            solve(ans, size, edges, edge.v, u, n);
        } else if (edge.v == u && edge.u != fa) {
            ans[edge.u] = ans[u] + n - 2 * size[edge.u];
            solve(ans, size, edges, edge.u, u, n);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i].id = i;
    }
    vector<Edge> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    auto ans = vector<int>(n, 0);
    auto size = vector<int>(n, 1);
    dfs(ans, size, edges, 0, -1, 0);
    solve(ans, size, edges, 0, -1, n);
    for (auto a : ans) {
        cout << a << " ";
    }
    return 0;
}