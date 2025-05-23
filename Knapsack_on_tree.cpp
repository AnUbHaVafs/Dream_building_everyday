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

const int MAXN = 5010;
int N, K;
vector<int> g[5010];
int arr[5010];
int sz[5010];
int dp[5010][2][5010];

int dfs(int node, int par){
    sz[node] = 1;
    // initialize every node states with default values
    for(int i=0; i<=K; i++){
        dp[node][1][i] = (i==1) ? arr[node] : -INF;
        dp[node][0][i] = (i==0) ? 0 : -INF;
    }

    for(auto v: g[node]){
        if(v==par)continue;
        dfs(v,node);
        int tmp0[MAXN], tmp1[MAXN];
        for (int i = 0; i < MAXN; i++) {
            tmp0[i] = tmp1[i] = -INF;
        }
        for(int a=sz[node]; a>=0; a--){
            for(int b=sz[v]; b>=0; b--){
                if(a+b>=MAXN)continue;
                int bestV = max(dp[v][1][b], dp[v][0][b]);
                if(dp[node][0][a]!=-INF && bestV!=-INF){
                    tmp0[a + b] = max(tmp0[a + b], dp[node][0][a] + bestV);
                }
                if(dp[v][0][b]!=-INF && dp[node][1][a]!=-INF){
                    tmp1[a + b] = max(tmp1[a + b], dp[node][1][a] + dp[v][0][b]);
                }
            }
        }
        sz[node] += sz[v];
        for (int i = 0; i <= sz[node]; i++) {
            dp[node][0][i] = max(dp[node][0][i], tmp0[i]);
            dp[node][1][i] = max(dp[node][1][i], tmp1[i]);
        }
    }
}

void solve()
{
    cin>>N;
    K = N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
        g[i].clear();
    }
    for(int i=1; i<=N-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0);
    for(int i=1; i<=N; i++){
        int maxProfit = max(dp[1][0][i], dp[1][1][i]);
        if(maxProfit==-INF){
            cout<<"F";
        }
        else{
            cout<<maxProfit;
        }
        cout<<" ";
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;  
    while (tt--)
    {
        solve();
    }
    return 0;
}