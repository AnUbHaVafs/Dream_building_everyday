#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,m,t;
int poles[101];
int dp[2][101][20001];

int rec(int level, int prev_empty, int t_left){
    // base case
    if(level==n){
        if(t_left){
            return 1e5;
        }
        else return 0;
    }
    if(t_left == 0){
        return 0;
    }
    
    // cache check
    if(dp[prev_empty][level][t_left] != -1){
        return dp[prev_empty][level][t_left];
    }
    
    // transitions
    int totalPoles = 1e5;
    
    // stand people in this row
    int people_left = t_left - (m - (2 * (poles[level])));
    totalPoles = min(totalPoles, poles[level] + rec(level + 1, false, max(0, people_left)));
    
    // skip this row
    if(!prev_empty){
        totalPoles = min(totalPoles, rec(level+1, true, t_left));
    }

    // save and return
    return dp[prev_empty][level][t_left] = totalPoles;
}

void solve()
{
    for(int i=0;i<n;i++){
        cin>>poles[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,false,t)<<endl;
}

int main()
{
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        while(cin>>n>>m>>t){
            solve();
        }
    }
    return 0;
}
