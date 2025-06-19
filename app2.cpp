#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[20][(1<<20)];
bool isEdge[20][20];
int n, m;
int cur;

// look vide editorial : for some more idea, 
// which to iterate, which to mask, bipartite matching, hamiltonian path variations

// If graph is not symmetric then, no of hamiltonian cycles would depend on starting node

// dummy node 0 connect all other nodes idea can be used

// visiting only those nodes which are greater than curr allow us to do traversal in controlled manner or in lexicographical order avoiding same cycle count redundancy(in case of undirected graph)

// A ham cy = A ham path + edge(curr->start)
// and A ham path from x->y and y->x is counted twices, therefore,
// cycles count = total_count/2

// we can only store the bool edges[u][v] rather than entire v<i>g[nodes]

// using sz allow us to count cycles of nodes count>2, not necessarily a cycle needs to contain all nodes
int dfs(int pos, int vis, int sz) {
    if(dp[pos][vis] != -1) {
        return dp[pos][vis];
    }
    int ans = 0;
    if(sz > 2 && isEdge[pos][cur]) {
        ans++;
    }
    for (int i = cur; i < n; ++i) {
        if((vis & (1<<i))) continue;
        if(isEdge[pos][i]) {
            ans += dfs(i, (vis | (1<<i)), sz+1);
        }
    }
    return dp[pos][vis]=ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        isEdge[a][b] = isEdge[b][a] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cur = i;
        memset(dp, -1, sizeof(dp));
        ans += dfs(i, (1<<i), 1);
    }
    cout << ans/2;
    return 0;
}