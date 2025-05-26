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
const ll MOD = 1e9+7;
const int INF = 1e9;
const ll LLINF = 1e18;

const int N = 100100;
int n;
vector<int> g[N];
ll dp[100100][2];

void dfs(int node, int par){
    dp[node][0] = (ll)1;
    dp[node][1] = (ll)1;
    for(int v:g[node]){
        if(v!=par){
            dfs(v, node);
            dp[node][0] = (dp[node][0] * dp[v][1])%MOD;
            dp[node][1] = (dp[node][1] * (dp[v][1] + dp[v][0])%MOD) % MOD;
        }
    }
}

void clear(){
    for(int i=1; i<=n-1; i++){
        dp[i][0] = dp[i][1] = (ll)0;
        g[i].clear();
    }
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0);
    ll ans = (dp[1][1]+dp[1][0])%MOD;
    cout<<ans<<endl;
    clear();
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