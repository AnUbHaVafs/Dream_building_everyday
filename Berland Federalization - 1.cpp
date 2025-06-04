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
const int N = 405;
const int K = 405;

int n,k;
vector<int> g[N];
int dp[N][K][2];
int subtree[N];

void dfs2(int node, int par){
    subtree[node] = 1;
    for(int v:g[node]){
        if(v!=par){
            dfs2(v,node);
            subtree[node] += subtree[v];
        }
    }
}

void dfs(int node, int par){    
    int sz = subtree[node];
    // 1-size node
    // subtree-size node
    dp[node][1][1] = g[node].size()-(par!=0);
    dp[node][1][0] = dp[node][1][1] + (par!=0);
    dp[node][sz][1] = 0;
    dp[node][sz][0] = (par!=0);
    for(int v:g[node]){
        if(v!=par){
            dfs(v, node);
            // merging logic
            for(int i=k; i>=0; i--){
                for(int j=k; j>=0; j--){
                    if(i+j<=k && i+j<=sz){
                        dp[node][i+j][0] = min(dp[node][i+j][0], dp[node][i][0] - 1 + dp[v][j][1]);
                    }
                }
            }
        }
    }
    for(int i=0; i<=k; i++){
        dp[node][i][1] = dp[node][i][0] - (par!=0);
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
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    dfs2(1,0);
    dfs(1,0);
    int minCuts = INF;
    for(int i=1; i<=n; i++){
        minCuts = min(minCuts, dp[i][k][0]);
    }
    cout<<minCuts<<endl;
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