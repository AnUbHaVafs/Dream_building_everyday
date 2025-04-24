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

int n;
int rec(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(grid[i][j]==0){
        return 0;
    }
    // cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    // no valid move assumed initially
    int ans = 0; 
    int steps = grid[i][j];
    // move right
    if(j + steps < n){
        ans += rec(i, j+steps, grid, dp);
    }
    // move down
    if(i + steps < n){
        ans += rec(i+steps, j, grid, dp);
    }
    return dp[i][j] = ans;
}

void solve()
{
    cin>>n;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n));
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            char c;
            cin>>c;
            grid[i][j] = c-'0';
            dp[i][j] = -1;
        }
    }
    cout<<rec(0,0,grid,dp);

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}