#include <bits/stdc++.h>
using namespace std;

// #define Anubhav(i,n) \
//         for(int i=0;i<n;i++)
// typedef long long ll;
using ll = long long;

const int N = 100000;
ll toys[N];
int n;
ll dp[N+1][4];

ll rec(int level, int prev_jump){
    if(level==n)return 0;

    if(dp[level][prev_jump]!=-1){
        return dp[level][prev_jump];
    }

    ll ans=0;
    // leonard move
    if(prev_jump==0){
        if(level<n)ans = max(ans, toys[level] + rec(level+1,1));
        if(level+1<n)ans = max(ans, toys[level] + toys[level+1] + rec(level+2,2));
        if(level+2<n)ans = max(ans, toys[level] + toys[level+1] + toys[level+2] + rec(level+3,3));
    }
    // sheldon move
    else{
        int min_jump_level = min(level+prev_jump, n);
        ans = rec(min_jump_level,0);
    }
    return dp[level][prev_jump] = ans;
}

void solve()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>toys[i];
    // for(int i=0;i<n;i++)cout<<toys[i];
    cout<<rec(0,0);
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
        if(tt!=0)cout<<endl;
    }
    return 0;
}
