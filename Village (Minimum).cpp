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
int n, K;
vector<int> g[N];
int ng[N];
int sz[N];
bool dp[N];
int ans = 0;

void dfs2(int node, int par){

    for(int v:g[node]){
        if(v!=par){
            dfs2(v,node);
            if(dp[v]==false){
                // mark replaced
                dp[node] = true;
                dp[v] = true;
                // add replace cost
                ans += 2;
                // track new positions
                ng[v] = ng[node];
                ng[node] = v;
            }
        }  
    }    
}

void clear(){
    for(int i=1; i<=n; i++){
        g[i].clear();
    }
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n; i++){
        dp[i] = false;
        g[i].clear();
        ng[i] = i;
    }
    for(int i=1; i<=n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs2(1,0);
    if(!dp[1]){
        ans += 2;
        dp[1] = true;
        ng[1] = ng[g[1][0]];
        ng[g[1][0]] = 1;
    }
    cout<<ans<<endl;
    for(int i=1; i<=n; i++){
        cout<<ng[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    IOS
    int tt=1;
    // cin >> tt;  
    while (tt--)
    {
        solve();
    }
    return 0;
}