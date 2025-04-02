#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int n,t;
bool vis[51];
int times[N][N];
int costs[N][N];
pair<int,int> dp[100][1001];

pair<int,int> rec(int level, int time_left){
    if(level==n-1){
        return {0,0};
    }
    if(time_left==0){
        return {1e9,1e9};
    }
    if(dp[level][time_left].first!=-1 && dp[level][time_left].second!=-1){
        return dp[level][time_left];
    }
    // mark current state as visited
    vis[level]=true;
    int minCost=1e9, corrpTime=1e9;
    for(int i=0;i<n;i++){
        if (!vis[i] && i != level && times[level][i] <= time_left)
        {
            pair<int,int> costAndTime = rec(i, time_left - times[level][i]);
            int cost = costAndTime.first, time = costAndTime.second;
            if((costs[level][i] + cost)<minCost){
                minCost = costs[level][i] + cost;
                corrpTime = times[level][i] + time;
            }
        }
    }
    vis[level]=false;
    return dp[level][time_left] = {minCost, corrpTime};
}

void solve()
{
    // time 2d input
    // int times[n][n];
    // vector<vector<int>>times(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>times[i][j];
            // cout<<times[i][j]<< " ";
        }
        // cout<<endl;
    }
    // time = times;
    // toll 2d input
    // int cost[n][n];
    // vector<vector<int>>cost(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>costs[i][j];
            // cout<<costs[i][j]<<" ";
        }
        // cout<<endl;
    }
    memset(vis,false,sizeof(vis));
    // memset(dp,-1,sizeof(dp));
    for(int i=0;i<100;i++){
        for(int j=0;j<1001; j++){
            dp[i][j]={-1,-1};
        }
    }
    auto ans = rec(0, t);
    if (ans.first >= 1e9) {
        cout << "-1 -1"; // No valid path found within time limit
    } else {
        cout << ans.first << " " << ans.second;
    }
    cout<<endl;
}

int main()
{
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        while(cin>>n>>t && n!=0 && t!=0){
            // cout<<n<<t<<endl;
            solve();
        }
    }
    return 0;
}


// how to store 2d array from local to global