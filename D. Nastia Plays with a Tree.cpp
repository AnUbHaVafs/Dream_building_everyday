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
int n;
int ans = 0; // min ops
vector<pii> g[N];
bool dp[N]; // true: if sz(node)>=2 after removing those ci which has dp[i]= true means only having those deg<=1 need to remvoe the edge b/w this node and par
bool vis[N];
bool isDeleted[N];
vector<pii> deleted_edges;

// bottom-up dp // post-order traversal
// cal deg[node]
void dfs(int node, int par)
{
    int sz = g[node].size() - (par!=0);
    // delete all ci such that deg[ci]>=2
    for(auto to: g[node]){
        int v = to.first, ei = to.second;
        if(v!=par){
            dfs(v,node);
            if(dp[v]){
                sz--;
                ans++;
                deleted_edges.pb({node,v});
                isDeleted[ei] = true;
            }
        }
    }

    // delete all ci until there is atmost 1 sz(deg) for curr node
    if(sz>=2){
        dp[node] = true;
        for(auto to:g[node]){
            int v = to.first, ei = to.second;
            if(v!=par){
                if(sz<=2){
                    break;
                }
                if(!dp[v]){
                    sz--;
                    ans++;
                    deleted_edges.pb({node, v});
                    isDeleted[ei] = true;
                }
            }
        }
    }
}

vector<int> leaf_nodes;
void dfs2(int node, int par){
    vis[node] = true;
    int size = 0;
    for(auto to: g[node]){
        int v = to.first, ei = to.second;
        if(!isDeleted[ei] && !vis[v]){
            size++;
            dfs2(v,node);
        }
    }
    if(node==par && size==1){ // leaf node
        leaf_nodes.pb(node);
    }
    else if(size==0){ // this is another but also a leaf node
        leaf_nodes.pb(node);
    }
}

vector<pii> leafs;
vector<pii> added_edges;
void solve(){
    cin>>n;
    for(int i=1; i<=n; i++){
        g[i].clear();
        dp[i] = false;
        vis[i] = false;
        isDeleted[i] = false;
    }
    deleted_edges.clear();
    added_edges.clear();
    leafs.clear();
    ans = 0;
    for(int i=1; i<=n-1; i++){
        int u,v;
        cin>>u>>v;
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    dfs(1,0); // 1-root
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs2(i, i); // get 2 leaf-nodes of this single path
            if(leaf_nodes.size()==2){
                leafs.pb({leaf_nodes[0], leaf_nodes[1]});
            }
            else if(leaf_nodes.size()==1){
                leafs.pb({leaf_nodes.back(), leaf_nodes.back()});
            }
            leaf_nodes.clear();
        }
    }
    // add nodes and keep track of added_edges
    for(int i=1; i<leafs.size(); i++){
        added_edges.pb({leafs[i-1].second, leafs[i].first});
    }

    cout<<ans<<endl;
    for(int i=0; i<deleted_edges.size(); i++){
        cout<<deleted_edges[i].first<<" "<<deleted_edges[i].second<<" ";
        cout<<added_edges[i].first<<" "<<added_edges[i].second<<endl;
    }
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