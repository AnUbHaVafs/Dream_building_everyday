#include<bits/stdc++.h>
using namespace std;

int n,t;
const int N = 101;
int times[N][N];
int risks[N][N];
bool vis[101];
pair<int,int> dp[101][251];

pair<int, int> rec(int level, int time_left){
    if(level==n-1){
        return {0,0};
    }
    if(time_left==0){
        return {1e9,1e9};
    }
    if(dp[level][time_left].first!=-1){
        return dp[level][time_left];
    }
    vis[level]=true;
    int minRisk = 1e9, corrTime = 1e9;
    for(int station=0; station<n; station++){
        if(!vis[station] && station!=level && times[level][station]<=time_left){
            pair<int,int> riskAndTime = rec(station, time_left-times[level][station]);
            int risk = riskAndTime.first, time = riskAndTime.second;
            if(risk+risks[level][station]<minRisk){
                minRisk = risks[level][station] + risk;
                corrTime = times[level][station] + time;
            }
        }
    }
    vis[level]=false;
    return dp[level][time_left] = {minRisk, corrTime};
}

void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>times[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>risks[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    for(int i=0;i<101;i++){
        for(int j=0;j<251;j++){
            dp[i][j] = {-1,-1};
        }
    }
    auto ans = rec(0,t);
    if(ans.first>=1e9){
        cout<<"-1";
    }
    else{
        cout<<ans.first<<" "<<ans.second;
    }
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        cin>>n>>t;
        solve();
        if(tt!=0)cout<<endl;
    }
    return 0;
}