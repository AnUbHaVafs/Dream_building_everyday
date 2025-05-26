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
const int INF = 1e9;

const int MAXN = 100100;
int N,K;
vector<int> tree[MAXN];
int indp[MAXN][501];
int outdp[MAXN][501];

// O(N*K)
// bottom-up || postorder traversal
void dfsin(int node, int par){
    indp[node][0] = 1;
    for(int i=1; i<=K; i++){
        indp[node][i] = 0;
    }
    for(int v:tree[node]){
        if(v!=par){
            dfsin(v,node);
            for(int i=1; i<=K; i++){
                indp[node][i] += indp[v][i-1];
            }
        }
    }
}

// top-down // preorder traversal
void dfsout(int node, int par){
    for(int i=0; i<=K; i++){
        outdp[node][i] = 0;
    }

    if(par!=0){
        for(int i=1; i<=K; i++){
            outdp[node][i] = outdp[par][i-1] + (indp[par][i-1] - (i>=2 ? indp[node][i-2] : 0));
        }
    }
    for(int v:tree[node]){
        if(v!=par){
            dfsout(v,node);
        }
    }
}

void solve()
{
    cin>>N>>K;
    for(int i = 1; i <= N; i++){
        for (int j = 0; j <= K; j++) {
            indp[i][j] = 0;
            outdp[i][j] = 0;
        }
        tree[i].clear();
    }
    
    for(int i=1; i<=N-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfsin(1,0);
    dfsout(1,0);
    int ans = 0;
    for(int i=1; i<=N; i++){
        ans += (indp[i][K] + outdp[i][K]);
    }
    cout<<(ans/2)<<endl;
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