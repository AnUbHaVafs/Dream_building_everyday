#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define pii pair<int, int>
#define ALL(x) (x).begin(), (x).end()
#define psi pair<string, int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD = 1e9+7;
const int INF = 1e9;
const ll LLINF = 1e18;

const int N = 455;
const int K = 455;
int n,k, edge[N][K], pos[N][K];
vector<int> g[N];
set<int> dp[N][K];

void dfs(int node, int par=1){
    // base case
    pos[node][0] = pos[node][1] = 1;
    if(node!=1) dp[node][1].insert(edge[node][par]);
    for(int v:g[node]){
        if(v!=par){
            dfs(v, node);
            for(int sz=k; sz>=1; sz--){
                if(pos[node][sz]) dp[node][sz].insert(edge[node][v]);
                for(int j=1; j<sz; j++){
                    if(!pos[v][j] || !pos[node][sz-j])continue;
                    if(pos[node][sz] && dp[node][sz].size() <= dp[node][sz-j].size() + dp[v][j].size() - 1) continue;
                    dp[node][sz] = set<int>();
                    if(node!=1) dp[node][sz].insert(edge[node][par]);
                    for(auto i: dp[node][sz-j]) dp[node][sz].insert(i);
                    for(auto i: dp[v][j]) dp[node][sz].insert(i);
                    dp[node][sz].erase(edge[node][v]);
                    pos[node][sz] = 1;
                }
            }
        }
    }
}

void solve()
{
    cin>>n>>k;
    for(int i=1; i<=n-1; i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
        edge[u][v] = edge[v][u] = i;
    }
    dfs(1);
    int ans = INF, ansNode = 0;
    for(int i=1; i<=n; i++){
        if(!pos[i][k])continue;
        if(dp[i][k].size()<ans){
            ans = dp[i][k].size(); // minCuts // cut-edges setSize
            ansNode = i;
        }
    }
    cout<< (ans==INF ? 0 : ans) <<endl;
    for(auto i: dp[ansNode][k]){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    IOS
    int tt = 1;
    // cin >> tt;  
    while (tt--)
    {
        solve();
    }
    return 0;
}