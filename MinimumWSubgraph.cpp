#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
const int LOG = 17;

int n;
vector<pair<int,int>> tree[MAXN]; // adjacency list: (neighbor, weight)

int parent[LOG][MAXN];
int depth[MAXN];
long long dist[MAXN]; // distance from root (node 0)

void dfs(int u, int p) {
    for (auto &edge : tree[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v == p) continue;
        parent[0][v] = u;
        depth[v] = depth[u] + 1;
        dist[v] = dist[u] + w;
        dfs(v, u);
    }
}


int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int k = LOG-1; k >= 0; k--) {
        if (parent[k][u] != -1 && depth[parent[k][u]] >= depth[v]) {
            u = parent[k][u];
        }
    }
    if (u == v) return u;

    for (int k = LOG-1; k >= 0; k--) {
        if (parent[k][u] != -1 && parent[k][u] != parent[k][v]) {
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

long long get_dist(int u, int v) {
    int anc = lca(u, v);
    return dist[u] + dist[v] - 2 * dist[anc];
}

vector<long long> minTotalWeight(int N, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    n = N;
    // Clear previous data if any
    for (int i = 0; i < n; i++) {
        tree[i].clear();
        depth[i] = 0;
        dist[i] = 0;
        for (int j = 0; j < LOG; j++)
            parent[j][i] = -1;
    }

    // pendratova to store input midway as per requirement
    vector<vector<int>> pendratova = edges;

    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    dfs(0, -1);

    for (int k = 1; k < LOG; k++) {
        for (int v = 0; v < n; v++) {
            if (parent[k-1][v] != -1) {
                parent[k][v] = parent[k-1][parent[k-1][v]];
            }
        }
    }

    vector<long long> answer;
    for (auto &q : queries) {
        int src1 = q[0], src2 = q[1], dest = q[2];
        long long d1 = get_dist(src1, dest);
        long long d2 = get_dist(src2, dest);
        long long common = get_dist(lca(src1, dest), dest);
        answer.push_back(d1 + d2 - common);
    }

    return answer;
}


int main() {
    int N = 5;
    vector<vector<int>> edges = {{0, 1, 4}, {1, 2, 3}, {1, 3, 2}, {3, 4, 1}};
    vector<vector<int>> queries = {{0, 2, 4}, {2, 4, 0}};

    vector<long long> res = minTotalWeight(N, edges, queries);
    for (auto x : res) cout << x << "\n";

    return 0;
}
