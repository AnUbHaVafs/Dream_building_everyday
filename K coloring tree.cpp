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

int N,K;
vector<vector<pair<ll,ll>>> g;
ll dp[1000100][2];
// dp[node][0] --> max val when we choosen atmost k-1 edges (merged with par case)
// dp[node][1] --> max val when we choosen exactly k edges (not-merged with parent case)

// in-dp vairant bottom-up merging child values
void dfs(int node, int par){
    // leaf node case
    dp[node][0] = dp[node][1] = 0;
    ll base = 0;
    vector<ll> delta;
    for(auto v:g[node]){
        if(v.first!=par){
            dfs(v.first,node);
            base += dp[v.first][1];
            delta.pb(-dp[v.first][1] + v.second + dp[v.first][0]);
        }
    }
    sort(delta.begin(), delta.end());
    delta.pb(0); // 0 --> taken 0 no. of edges --> corresponds to dp[node][0] case
    reverse(delta.begin(), delta.end());
    for(int ch=0; ch<delta.size(); ch++){
        base+=delta[ch];
        if(ch==K){
            dp[node][1] = max(dp[node][1], base); // best value for choosing exactly k edges
            break;
        }
        dp[node][0] = max(dp[node][0], base); // best value for atmost k-1 edges
        dp[node][1] = max(dp[node][1], base); // best value for atmost k-1 edges
    }
}

void solve()
{
    cin>>N>>K;
    g.clear();
    g.resize(N+1);
    for(int i=1; i<=N-1; i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].pb(make_pair(b,c));
        g[b].pb(make_pair(a,c));
    }
    dfs(1,0);
    cout<<dp[1][1]<<endl;
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