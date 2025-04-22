#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int n, k;
int pos[100];
unordered_map<int,int> openPos;

int dp[100][100];

int rec(int level, int openCount){
    // cout<<level<<" "<<openCount<<endl;
    if(level==2*n+1){
        return (openCount == 0);
    }

    // cache check
    if(dp[level][openCount]!=-1){
        return dp[level][openCount];
    }

    int ans = 0;
    if(openPos[level]){
        ans += rec(level+1, openCount+1);
    }
    else{
        ans += rec(level+1, openCount+1);
        if(openCount>0){
            ans += rec(level + 1, openCount-1);
        }
    }

    return dp[level][openCount] =  ans;
}

void solve()
{
    unordered_map<int, int> newOpenPos;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>pos[i];
        newOpenPos[pos[i]]++;
    }
    openPos = newOpenPos;
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,0)<<endl;
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