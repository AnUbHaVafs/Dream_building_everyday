#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N,M;
int dp[101][101];

int rec(int i, int j, vector<vector<int>> &grid){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int j1=-1; j1<=1; j1++){
        int nj = j+j1;
        int ni = i-1;
        if(ni>=0 && nj>=0 && nj<M){
            ans = min(ans, rec(ni, nj, grid) + grid[ni][nj]);
        }
    }
    return dp[i][j] = ans==INT_MAX ? 0 : ans;
}

void solve()
{
    vector<vector<int>> grid(N+1, vector<int>(M));
    // in between cities
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>grid[i][j];
        }
    }
    // destination city price set to 0
    for(int j=0; j<M; j++){
        grid[N][j]=0;
    }
    // cout<<N<<M<<endl;
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //         cout<<grid[i][j]<<" ";
    //     }cout<<endl;
    // }
    memset(dp,-1,sizeof(dp));
    int ans = INT_MAX;
    for(int j=0; j<M; j++){
        ans = min(ans, rec(N, j, grid));
        // cout<<rec(N,j,grid)<<" ";
    }
    cout<<ans<<endl;
}

int main()
{
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        while(cin>>N>>M){
            solve();
        }
    }
    return 0;
}
