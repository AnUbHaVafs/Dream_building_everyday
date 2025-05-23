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

// CodeForces: 2500 rated

const int N = 100100;

int n;
vector<vector<pair<int, int>>> g;

int ans = 0;
bool dp[N];
bool deleted[N];

void dfs(int node, int par){
    int sz = g[node].size() - (par!=-1);

    for(auto to:g[node]){
        if(to.first==par)continue;
        int v = to.first;
        int edge = to.second;
        dfs(v,node);
        if(dp[v]){ // this child v has deg>=2
            --sz;
            ++ans;
            deleted[edge] = true;
        }
    }

    if(sz>=2){
        dp[node] = true;
        for(auto to:g[node]){
            if(to.first==par)continue;
            int v = to.first;
            int edge = to.second;
            if(sz<=2)break;
            if(!dp[v]){
                --sz;
                ++ans;
                deleted[edge] = true;
            }
        }
    }
}

bool used[N];
vector<int> leaves;

void dfs2(int node, int root){
    used[node] = true;
    int ch=0;
    for(auto to:g[node]){
        if(!deleted[to.second] && !used[to.first]){
            ch++;
            dfs2(to.first, root);
        }
    }
    if(node==root && ch==1){ // leaf node
        leaves.pb(node);
    }
    else if(ch==0){ // this is another but also a leaf node
        leaves.pb(node);
    }
}

void clear(int n) {
    ans = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = false;
        g[i].clear();
    }
    leaves.clear();
}

void solve()
{
    cin>>n;
    g.clear();
    g.resize(n);
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        g[u].pb({v,i}); // 1. Whenever we need to keep track of edges, assign unique index to edges and store them in graph
        g[v].pb({u,i});
    }
    dfs(0, -1); // delete the edges

    vector<pair<int, int>> bamboo;
    // get the endpoints or leaf nodes for every path created in a forest
    for(int i=0; i<n; i++){
        if(!used[i]){
            dfs2(i,i);
            if(leaves.size()==2){
                bamboo.pb({leaves[0], leaves[1]});
            }
            if(leaves.size()==1){
                bamboo.pb({leaves.back(), leaves.back()});
            }
            leaves.clear();
        }
    }
    vector<pair<int, int>> deleted_edges, added_edges;
    for(int i=0; i<n-1; i++){
        for(auto to:g[i]){
            int v = to.first;
            int edge = to.second;
            if(deleted[edge]){
                if(i<v){
                    deleted_edges.pb({i,v});
                }
            }
        }
    }
    // get the added edges by connecting 2 leaf nodes fro, 2 different bamboos/components
    for(int i=1; i<bamboo.size(); i++){
        added_edges.pb({bamboo[i-1].second, bamboo[i].first});
    }

    cout<<ans<<endl;
    // for(auto d: deleted_edges){
    //     cout<<d.first+1<<" "<<d.second+1<<" ";
    // }
    // for(auto a: added_edges){
    //     cout<<a.first+1<<" "<<a.second+1<<" ";
    // }
    // int m = min(deleted_edges.size(), added_edges.size());
    for(int i=0; i<deleted_edges.size(); i++){
        cout << deleted_edges[i].first + 1 << " " << deleted_edges[i].second + 1<<" ";
        cout << added_edges[i].first + 1 << " " << added_edges[i].second + 1<<" ";
        cout<<endl;
    }

    for (int i = 0; i < n; i++) used[i] = false;
    for (int i = 0; i < n - 1; i++) deleted[i] = false;
    clear(n);
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