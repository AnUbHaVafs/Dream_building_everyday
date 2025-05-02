#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define pii pair<int, int>
#define psi pair<string, int>
#define pb push_back
#define f first
#define s second
const int mod = 1e9 + 7;

int N;
ll arr[3001];
ll dp[3001][3001][2];

// max value Taro(p1) can form if both players play optimally at each turn
ll rec(int l, int r, int p1){
    // base case
    if(l==r){
        return (p1==1) ? arr[l] : (ll)0;
    }

    // cache check
    if(dp[l][r][p1]!=-1){
        return dp[l][r][p1];
    }
    // compute and transitions
    ll ans = (ll)0;
    // Taro's turn (for Taro's score to be max.)
    if(p1==1){
        ll remFront = arr[l] + rec(l+1,r,0);
        ll remBack = arr[r] + rec(l,r-1,0);
        ans = max(remFront, remBack);
    }
    // Jiro's turn (Take min for Taro's score to be min)
    else{
        ll remFront = 0 + rec(l + 1, r, 1);
        ll remBack = 0 + rec(l, r - 1, 1);
        ans = min(remFront, remBack);
    }
    // save and return
    return dp[l][r][p1] = ans;
}

void solve()
{
    cin>>N;
    ll ts = 0;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        ts += arr[i];
    }
    SET(dp);
    ll taroScore = rec(0,N-1,1);
    ll jiroScore = ts - taroScore;
    ll ans = taroScore - jiroScore;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}