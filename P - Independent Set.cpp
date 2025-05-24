#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int N = 1e5 + 5;

vector<int> g[N];
ll dp[N][2];

void dfs(int u, int parent) {
    dp[u][0] = dp[u][1] = 1;
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u);
        dp[u][0] = dp[u][0] * ((dp[v][0] + dp[v][1]) % MOD) % MOD; // white
        dp[u][1] = dp[u][1] * dp[v][0] % MOD;                      // black
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1]) % MOD << "\n";
    return 0;
}
