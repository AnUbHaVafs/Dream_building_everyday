#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define pii pair<int, int>
#define psi pair<string, int>
#define MPi make_pair(int, int)
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD = 1e9+7;
const int INF = 1e9;
const ll LLINF = 1e18;

int N,K;
int arr[1000100];
vector<pii> g[1000100];
int prefixSum[1000100];
int dp[1000100];

void dfs(){}

void solve()
{
    cin>>N>>K;
    for(int i=1; i<=N; i++){
        g[i].clear();
    }
    for(int i=1; i<=N-1; i++){
        int u, v, w;
        cin>>u>>v>>w;
        g[u].pb(make_pair(v,w));
        g[v].pb(make_pair(u,w));
    }
    // dfs(1,0);
    // cout<<prefixSum[1][K]<<endl;
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