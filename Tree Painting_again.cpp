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

void setIO(string s)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int MAXN = 200100;
int N;
vector<int> g[MAXN];
ll dp[MAXN], subtreeSize[MAXN];
ll ans;

void dfs1(int node, int par=1){
    subtreeSize[node]=1;
    for(int v:g[node]){
        if(v!=par){
            dfs1(v, node);
            subtreeSize[node] += subtreeSize[v];
        }
    }
}

void dfs2(int node, int par=1){
    for(int v:g[node]){
        if(v!=par){
            // preorder traversal
            dp[v] = dp[node] - subtreeSize[v] + (N - subtreeSize[v]);
            ans = max(ans, dp[v]);
            dfs2(v, node);
        }
    }
}

void solve()
{
    cin>>N;
    // clear
    for(int i=1; i<=N; i++){
        dp[i] = 0;
        subtreeSize[i] = 0;
        ans = 0;
    }
    for(int i=1; i<=N-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(1);
    ll base = 0;
    for(int i=1; i<=N; i++){
        base += subtreeSize[i];
    }
    ans = dp[1] = base;
    dfs2(1);
    // for(int i=1; i<=N; i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
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