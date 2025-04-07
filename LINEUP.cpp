#include <bits/stdc++.h>
using namespace std;

const int N = 12;
int field[N][N];
bool vis[N];
string s;
unordered_map<string, vector<int>> dp;

int rec(int i){ // max. poss. strength of players[0...level] if levelth player has been assigned pos position
    if(i==0){
        return 0;
    }

    if(!dp[s].size()){
        vector<int> pos(N,-1);
        dp[s] = pos;
    }
    if(dp[s].size() && dp[s][i]!=-1){
        return dp[s][i];
    }
    
    int ans=0;
    for(int pos=1;pos<N;pos++){
        if(!vis[pos] && field[i][pos]!=0){
            vis[pos]=true;
            s[pos]='1';
            ans = max(ans, field[i][pos] + rec(i-1));
            vis[pos]=false;
            s[pos]='0';
        }
    }
    return dp[s][i] = ans;
}

void solve()
{
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            cin>>field[i][j];
        }
    }
    // 1st row default values
    for(int j=0;j<N;j++){
        field[0][j] = 0;
    }
    // 1st column default values
    for(int i=0; i<N;i++){
        field[i][0] = 0;
    }
    memset(vis,false,sizeof(vis));
    for(int i=0;i<N;i++){
        s += "0";
    }
    // cout<<s<<endl;

    int ans=0;
    for(int pos=0;pos<N;pos++){
        ans = max(ans, rec(N-1));
    }
    cout<<ans<<endl;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
