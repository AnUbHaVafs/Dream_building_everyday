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

const ll MAXN = 200100;
ll N;
pair<ll,ll> a[MAXN];
vector<int> g[MAXN];
ll dp[MAXN][2];

void dfs(int node, int par=1){
    // base case
    dp[node][0] = 0; // dp[node][0] --> al value is assigned
    dp[node][1] = 0; // dp[node][1] --> ar value is assigned
    for(int v:g[node]){
        if(v!=par){
            dfs(v, node);
            dp[node][0] += max(abs(a[node].first-a[v].first) + dp[v][0], abs(a[node].first-a[v].second) + dp[v][1]);
            dp[node][1] += max(abs(a[node].second - a[v].first) + dp[v][0], abs(a[node].second - a[v].second) + dp[v][1]);
        }
    }
    // cout<<node<<": "<<dp[node][0]<<" "<<dp[node][1]<<endl;
}

void solve()
{
    cin>>N;
    for(int i=1; i<=N; i++){
        g[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }
    for(int i=1; i<=N; i++){
        cin>>a[i].first>>a[i].second;
    }
    for(int i=1; i<=N-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    ll ans = max(dp[1][0], dp[1][1]);
    cout<<ans<<endl;
}

int main()
{
    IOS
    int tt;
    cin >> tt;  
    while (tt--)
    {
        solve();
    }
    return 0;
}