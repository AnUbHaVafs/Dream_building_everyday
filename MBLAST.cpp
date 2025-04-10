#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string s1, s2;
int K;
int N,M;
int dp[2001][2001];

int rec(int i, int j){ // min dist b/w [i..n-1] & [j..m-1]
    // cout<<i<<j<<endl;
    // base case
    if(i==N || j==M){
        // cout<<K*max(N-i, M-j)<<endl;
        return K*max(N-i, M-j);
    }
    // cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    // compute and transitions
    int dist = INT_MAX;
    // compare ith with jth
    dist = min(dist, abs(s1[i]-s2[j]) + rec(i+1, j+1));
    // compare the ith with blank _ with cost k
    dist = min(dist, K + rec(i+1, j));
    dist = min(dist, K + rec(i, j+1));
    // save and return
    return dp[i][j] = dist;
}

void solve()
{
    cin>>s1>>s2>>K;
    N = s1.size(), M = s2.size();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
}

int main()
{
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
