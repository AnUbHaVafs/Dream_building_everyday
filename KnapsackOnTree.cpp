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
const int mod = 1e9+7;
const int INF = 1e9;
const ll LLINF = 1e18;

const int MAXN = 5005;

int N;
int val[MAXN];
vector<int> tree[MAXN];
int subtreeSize[MAXN];

// dp[u][k][0] => max profit selecting k nodes in subtree of u, u NOT included
// dp[u][k][1] => max profit selecting k nodes in subtree of u, u INCLUDED
int dp[MAXN][MAXN][2];

void dfs(int u, int parent){
    subtreeSize[u] = 1;

    for(int i=0; i<=N; i++){
        dp[u][i][0] = dp[u][i][1] = -INF;
    }

    dp[u][0][0] = 0;
    dp[u][1][1] = val[u];

    for(int v:tree[u]){
        if(v==parent) continue;

        dfs(v,u);

        int temp[MAXN][2];
        for (int i = 0; i < MAXN; ++i) {
            temp[i][0] = temp[i][1] = -INF;
        }
        for(int i=0; i<=subtreeSize[u]; i++){
            for(int j=0; j<=subtreeSize[v]; j++){
                // Case 1: u not included
                if(dp[u][i][0]!=-INF){
                    int bestV = max(dp[v][j][0], dp[v][j][1]);
                    if(bestV!=-INF){
                        temp[i+j][0] = max(temp[i+j][0], dp[u][i][0] + bestV);
                    }
                }

                // Case 2: u included
                if(dp[u][i][1]!=-INF && dp[v][j][0]!=-INF){
                    temp[i+j][1] = max(temp[i+j][1], dp[u][i][1] + dp[v][j][0]);
                }
            }
        }
        subtreeSize[u] += subtreeSize[v];

        for(int i=0; i<=subtreeSize[u]; i++){
            dp[u][i][0] = temp[i][0];
            dp[u][i][1] = temp[i][1];
        }
    }
}

void solve()
{
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>val[i];
        tree[i].clear();
    }
    for(int i=1; i<=N-1; i++){
        int u, v;
        cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(1,0);

    for(int k=1; k<=N; k++){
        int res0 = dp[1][k][0], res1 = dp[1][k][1];
        if(res0<= -INF && res1<=-INF){
            cout<<"F ";
        }
        else{
            cout<<max(res0, res1)<<" ";
        }
    }
    cout<<endl;
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