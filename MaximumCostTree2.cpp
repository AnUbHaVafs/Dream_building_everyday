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
const int mod = 1e9+7;
const int inf = 1e9;

void solve()
{
    // inputs
    int n;
    cin>>n;
    ll total_sum = 0;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++){
        cin>>a[i];
        total_sum += a[i];
    }
    vector<vector<int>> g(n+1);
    for(int i=1; i<=n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // compute the cost_root & sum[v] at all nodes assuming node 1 as root node
    vector<ll> sum(n+1);
    ll cost_root = 0;
    function<void(int, int, int)> dfs = [&](int node, int par, int depth){
        cost_root += 1LL *depth*a[node];
        sum[node] = a[node];
        for(auto ch:g[node]){
            if(ch!=par){
                dfs(ch,node,depth+1);
                sum[node] += sum[ch];
            }
        }
    };
    dfs(1,0,0);
    ll max_cost = cost_root;
    ll min_cost = cost_root;
    function<void(int, int, ll)> dfs2 = [&](int node, int par, ll cost_node){
        for(int v: g[node]){
            if(v!=par){
                ll cost_v = cost_node + total_sum - (2*sum[v]);
                max_cost = max(max_cost, cost_v);
                min_cost = min(min_cost, cost_v);
                dfs2(v, node, cost_v);
            }
        }
    };
    dfs2(1,0,cost_root);
    cout<<max_cost<<" "<<min_cost<<endl;
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