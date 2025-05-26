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

const int N = 100100;
int n,k;
vector<int> g[N];
ll dp[N][3];
int col[N];

void dfs(int node, int par){
    for(int c=1; c<=3; c++){
        dp[node][c] = (col[node]!=0 && col[node]!=c) ? 0 : 1;
    }
    for(int v:g[node]){
        if(v!=par){
            dfs(v, node);
            dp[node][1] = (dp[node][1] * (dp[v][2] + dp[v][3])) % MOD;
            dp[node][2] = (dp[node][2] * (dp[v][1] + dp[v][3])) % MOD;
            dp[node][3] = (dp[node][3] * (dp[v][1] + dp[v][2])) % MOD;
        }
    }
}

void clear(){
    for(int i=1; i<=n; i++){
        col[i]=0;
        g[i].clear();
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
    memset(dp,0,sizeof(dp));
    memset(col,0,sizeof(col));
    for(int i=1; i<=k; i++){
        int node,c;
        cin>>node>>c;
        col[node] = c;
    }
    dfs(1,0);
    ll ans = ((dp[1][1] + dp[1][2])%MOD + dp[1][3])%MOD;
    cout<<ans<<endl;
    clear();
}

int main()
{
    IOS
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    int tt = 1;
    // cin >> tt;  
    while (tt--)
    {
        solve();
    }
    return 0;
}