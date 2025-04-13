#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
pair<int,int> pilots[10001];
int dp[10001][5001];

int rec(int ind, int cap, int n){
    if(n==0){
        return 0;
    }
    if(dp[n][cap]!=-1){
        return dp[n][cap];
    }
    int ans=INT_MAX;
    // we can't take both the cases in some conditions;
    int ass = ind-1-cap;
    if(ass==cap){
        return min(ans, pilots[ind].second + rec(ind+1, cap, n-1));
    }
    if(ass-cap==n){
        return min(ans, pilots[ind].first + rec(ind + 1, cap + 1, n - 1));
    }
    // curr pilot = Cap
    ans = min(ans, pilots[ind].first + rec(ind+1, cap+1, n-1));
    // curr pilot = Ass
    ans = min(ans, pilots[ind].second + rec(ind + 1, cap, n - 1));
    return dp[n][cap] = ans;
}

void solve()
{
    for(int i=1; i<=N; i++){
        cin>>pilots[i].first>>pilots[i].second;
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,0,N)<<endl;
}

int main()
{
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        while(cin>>N){
            solve();
        }
    }
    return 0;
}
