#include <bits/stdc++.h>
using namespace std;

long long N, M;
const long long n = 505;
#define ll long long
// vector<vector<long long>> A, B;
// vector<vector<long long>> prefixSumA, prefixSumB;
long long A[n][n], B[n][n], prefixSumA[n][n], prefixSumB[n][n];

long long dp[1001][1001];

void getPrefixSums(){
    for(long long i=0;i<=N;i++){
        for(long long j=0;j<=M;j++){
            if(i==0 || j==0){
                prefixSumA[i][j]=0, prefixSumB[i][j]=0;
            }
            else{
                prefixSumA[i][j] = prefixSumA[i][j-1] + A[i][j];
                prefixSumB[i][j] = prefixSumB[i-1][j] + B[i][j];
            }
        }
    }
}

long long rec(long long i, long long j){
    // pruning
    // base case
    if(i==0 || j==0){
        return 0;
    }
    // cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    // compute and transitions
    long long ans = 0;
    // either we go to A refinery
    ans = max(ans, prefixSumA[i][j] + rec(i-1,j));
    // or go to B refinery
    ans = max(ans, prefixSumB[i][j] + rec(i,j-1));
    // save and return
    return dp[i][j] = ans;
}

void solve()
{
    // inputs
    if(N==0 && M==0){
        return;
    }
    for(long long i=1;i<=N;i++){
        for(long long j=1;j<=M;j++){
            cin>>A[i][j];
        }
    }
    for(long long i=1;i<=N;i++){
        for(long long j=1;j<=M;j++){
            cin>>B[i][j];
        }
    }
    // pre-computations
    memset(dp,-1,sizeof(dp));
    memset(prefixSumA,0,sizeof(prefixSumA));
    memset(prefixSumB,0,sizeof(prefixSumB));
    getPrefixSums();
    // sol
    cout<<rec(N,M)<<endl;
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
