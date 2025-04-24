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

int n,m;
int x,y;
int P[21][21];
int dp[21][21][40005];
bool vis[21][21][40005];

int rec(int i, int j, int p_left){
    if(i==n && j==m){
        return p_left;
    }

    // cache check
    if(vis[i][j][p_left]){
        return dp[i][j][p_left];
    }

    int ans = -1; // assuming no possible moves
    // right move if have enough power
    if(j+1<=m && p_left-P[i][j+1]>=0){
        ans = max(ans, rec(i, j+1, p_left-P[i][j+1]));
    }
    // move bottom similarly
    if(i+1<=n && p_left-P[i+1][j]>=0){
        ans = max(ans, rec(i+1, j, p_left-P[i+1][j]));
    }
    vis[i][j][p_left] = true;
    return dp[i][j][p_left] = ans;
}

void solve()
{
    cin>>n>>m;
    cin>>x>>y;
    for(int i=1; i<=n ;i++){
        for(int j=1; j<=m; j++){
            cin>>P[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    memset(dp, -1, sizeof(dp));

    // for(int i=1; i<=21; i++){
    //     for(int j=1; j<=21; j++){
    //         for(int k=1; k<=40005; k++){
    //             vis[i][j][k] = false;
    //         }
    //     }
    // }
    
    int ans = rec(x,y,P[x][y]);
    if(ans==-1){
        cout<<"N"<<endl;
    }
    else{
        cout<<"Y "<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}