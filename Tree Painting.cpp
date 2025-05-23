#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define pii pair<int, int>
#define psi pair<string, int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD = 1e9+7;
const int INF = 1e9;
const ll LLINF = 1e18;

const int N = 200100;

int n;
vector<int> g[N];
int subtreeSize[N];
ll dp[N];
ll base = 0;

void dfs(int node, int par){
    subtreeSize[node] = 1;
    for(auto v:g[node]){
        if(v!=par){
            dfs(v,node);
            subtreeSize[node] += subtreeSize[v];
        }
    }
    base += (ll)subtreeSize[node];
}

void dfs2(int node, int par){
    if(node==1){
        dp[node] = base;
    }
    else{
        dp[node] = (ll)(dp[par] - (ll)subtreeSize[node] + ((ll)subtreeSize[1] - (ll)subtreeSize[node]));
    }
    for(int v:g[node]){
        if(v!=par){
            dfs2(v,node);
        }
    }
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n-1; i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0);
    dfs2(1,0);
    ll ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
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