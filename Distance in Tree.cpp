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

const int N = 50100;
const int K = 505;
int n, k;
vector<int> g[N];
ll indp[N][K];
ll outdp[N][K];

void dfsin(int node, int par){
    indp[node][0] = 1;
    for(int v:g[node]){
        if(v!=par){
            dfsin(v, node); //bottom-up dp // post-order traversal
            for(int i=1; i<=k; i++){
                indp[node][i] += (indp[v][i-1]);
            }
        }
    }
}

void dfsout(int node, int par){
    for(int v: g[node]){
        if(v!=par){
            // top-bottom dp // pre-order traversal
            for(int i=1; i<=k; i++){
                outdp[v][i] += (indp[node][i-1] + outdp[node][i-1]);
                if(i>=2){
                    outdp[v][i] -= indp[v][i-2];
                }
            }
            dfsout(v, node);
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
    cin>>n>>k;
    for(int i=1; i<=n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            indp[i][j] = 0;
            outdp[i][j] = 0;
        }
    }
    dfsin(1,0);
    dfsout(1,0);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + indp[i][k]);
        ans = (ans + outdp[i][k]);
    }
    cout << (ans/2) << endl;
    clear();
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