#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define pii pair<int, int>
#define psi pair<string, int>
#define f first
#define s second
const int mod = 1e9 + 7;

const int MAXN = 100090;
const int MOD = 10007;

int n;
vector<vector<int>> trees;
int dp[MAXN][2]; // dp[u][0] -> min. no. lights needed if light is not at u, dp[u][1] -> if lit is placed at u
int ways[MAXN][2]; // ways[u][0] --> no. of ways to achive to dp[u][0], ways[u][1] -> ways to achieve dp[u][1]

// min number of lights needed for optimal lighting + ways to achieve it
void dfs(int u, int parent){
    // for every node
    dp[u][0] = 0;
    dp[u][1] = 1;
    ways[u][0] = 1;
    ways[u][1] = 1;

    for(int v: trees[u]){
        if(v==parent){
            continue;
        }
        dfs(v,u);

        // if we place the light at u(parent) then we have choice to place at v or not
        dp[u][1] += min(dp[v][1], dp[v][0]);
        if(dp[v][1]<dp[v][0]){
            ways[u][1] = (ways[u][1] * ways[v][1])%MOD;
        }
        else if(dp[v][0]<dp[v][1]){
            ways[u][1] = (ways[u][1] * ways[v][0])%MOD;
        }
        else{
            ways[u][1] = (ways[u][1]*(ways[v][0] + ways[v][1])%MOD)%MOD;
        }

        // if we don't place the light at u then place the light necessarily at v
        dp[u][0] += dp[v][1];
        ways[u][0] = (ways[u][0] * ways[v][1])%MOD;
    }
}

void solve()
{
    cin>>n;
    vector<vector<int>> network(n+1, vector<int>());
    for(int i=1; i<=n-1; i++){
        int u,v;
        cin>>u>>v;
        network[u].push_back(v);
        network[v].push_back(u);
    }
    trees = network;
    dfs(1,0);
    int min_lights, total_ways;
    if(dp[1][0]<dp[1][1]){
        min_lights = dp[1][0];
        total_ways = ways[1][0];
    }
    else if(dp[1][1]<dp[1][0]){
        min_lights = dp[1][1];
        total_ways = ways[1][1];
    }
    else{
        min_lights = dp[1][0];
        total_ways = (ways[1][0] + ways[1][1])%MOD;
    }
     
    cout<<min_lights<<" "<<total_ways<<endl;
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