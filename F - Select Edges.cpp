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

const int N = 300100;

// KEY LEARNINGS (Variant of in-dp):
// 1. (0-> cooresponds to a case where we can choose at most k-1 edges);
//    (1-> cooresponds to a case where we can choose at most k edges);
// 2. A particular delta for edge will only be pushed when degree(v) > 0; else we cannot take this edge in any case

vector<pair<int, int>> g[N];
ll d[N];
int n; 
ll dp[N][2];
// dp[node][1] -> max poss sum of weights for at-most k choices
// dp[node][0] -> max poss sum of weights for at-most less than < k choices

// variant of in-dp
void dfs(int node, int par){
    dp[node][1] = dp[node][0] = (ll)0;
    ll base = 0;
    vector<ll> delta;
    for(auto to: g[node]){
        if(par==to.first)continue;
        int v = to.first;
        int w = to.second;
        dfs(v,node);
        base += dp[v][1];
        if(d[v]>0){
            delta.pb(-dp[v][1] + w + dp[v][0]); // I can only take this edge(delta) if incident edges at this v children given if >0 else I can't take this edge in any case.
        }
    }
    sort(delta.begin(), delta.end());
    delta.pb(0);
    reverse(delta.begin(), delta.end());
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
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>d[i];
        g[i].clear();
    }
    for(int i=1; i<=n-1; i++){
        int u, v, w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    // cout<<n<<endl;
    // for(int i=1; i<=n; i++){
    //     cout<<d[i]<<" ";
    // }cout<<endl;
    // for(int i=1; i<=n; i++){
    //     cout<<i<<"-> ";
    //     for(auto j:g[i]){
    //         cout<<"("<<j.first<<", "<<j.second<<"), ";
    //     }cout<<endl;
    // }cout<<endl;

    dfs(1,0);
    // for(int node=1; node<=n; node++){
    //     cout<<node<<"->"<<dp[node][1]<<" "<<dp[node][0]<<endl;
    // }
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