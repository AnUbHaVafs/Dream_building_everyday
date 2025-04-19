#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int we, wt;
int n;
pair<int,int> coins[501];
int dp[501][10005];

const string successMsg = "The minimum amount of money in the piggy-bank is ";
const string errorMsg = "This is impossible.";

// ll inf = 1e15;
int inf = 1e9;

int rec(int level, int w_left){
    if(w_left==0){
        return 0;
    }
    if(level==n){
        return w_left ? inf : 0;
    }

    if(dp[level][w_left]!=-1){
        return dp[level][w_left];
    }

    // transitions
    int ans = inf;
    // take (if possible)
    int val = coins[level].first;
    int w = coins[level].second;
    if(w<=w_left){
        ans = min(ans, val + rec(level, w_left-w));
    }
    ans = min(ans, 0 + rec(level+1, w_left));
    // cout<<ans<<endl;
    return dp[level][w_left] =  ans;
}

void solve()
{
    cin>>we>>wt;
    int wl = wt-we;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>coins[i].first>>coins[i].second; // {val,w}
    }
    memset(dp,-1,sizeof(dp));
    int res = rec(0,wl);
    if(res==inf){
        cout<<errorMsg<<endl;
    }
    else{
        cout<<successMsg<<res<<"."<<endl;
    }
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
