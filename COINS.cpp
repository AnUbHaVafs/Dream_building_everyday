#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> dp;
// vector<long long> dp(100000000, -1);

long long rec(long long N){
    if(N==0 || N==1)return N;
    if (dp.find(N) != dp.end()){
        return dp[N];
    }
    long long ans=0;
    ans = max(N, rec(floor(N/2)) + rec(floor(N/3)) + rec(floor(N/4)));
    return dp[N] = ans;
}

void solve()
{
    // vector<long long> dp(199999999, 0);
    // for (long long i = 0; i < (100000000); i++)
    // {
    //     dp[i] = (long long)-1;
    // }
    long long N;
    while(cin>>N){
        long long ans = 0;
        cout<<rec(N)<<endl;
        // for (long long i = 0; i < N + 1; i++)
        // {
        //     if (i == 0 || i == 1)
        //     {
        //         dp[i] = i;
        //     }
        //     else
        //     {
        //         dp[i] = (long long)(dp[floor(i / 2)] + dp[floor(i / 3)] + dp[floor(i / 4)]);
        //     }
        //     ans = max(ans, max(dp[i], i));
        // }
        // cout << max(ans, N)<<endl;
    }
}

int main()
{

    int tt;
    // cin >> tt;
    tt=1;
    while (tt--)
    {
        solve();
        if(tt!=0)cout<<endl;
    }
    return 0;
}
