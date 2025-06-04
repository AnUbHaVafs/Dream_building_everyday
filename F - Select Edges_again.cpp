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

const int MAXN = 300100;

ll N, d[MAXN];
vector<pii> g[MAXN];
ll dp[MAXN][2];
// dp[node][0] --> max poss weight sum if we can select at most di-1 edges (par edge is taken)
// dp[node][1] --> max poss weight sum if we can select at most di edges (par edge is not taken)

void dfs(int node, int par=1){
    // leaf node
    dp[node][0] = dp[node][1] = (ll)0;
    vector<ll> delta;
    ll base = 0;
    for(auto to:g[node]){
        int v = to.first;
        int w = to.second;
        if(v!=par){
            dfs(v, node);
            base += dp[v][1]; // not_take
            //change in base weight sum if we take this edge weight
            if(d[v]>0){
                delta.pb(w + dp[v][0] - dp[v][1]);
            }
        }
    }
    sort(ALL(delta));
    // for not-choosing any edge we put 0 as delta value at beginning
    delta.pb(0);
    reverse(ALL(delta));

    for(int ch=0; ch<delta.size(); ch++){
        base += delta[ch];
        base = max(base, (ll)0);
        if(ch==d[node]){ // max choices for a current node
            dp[node][1] = max(dp[node][1], base);
            break;
        }
        dp[node][1] = max(dp[node][1], base);
        dp[node][0] = max(dp[node][0], base);
    }
}

void solve()
{
    cin>>N;
    // clear logic
    for(int i=1; i<=N; i++){
        cin>>d[i];
        g[i].clear();
        dp[i][0] = dp[i][1] = -LLINF;
    }
    for(int i=1; i<=N-1; i++){
        int u, v, w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    dfs(1);
    cout<<dp[1][1]<<endl;
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