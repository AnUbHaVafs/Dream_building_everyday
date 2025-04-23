#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define pii pair<int, int>
#define psi pair<string, int>
#define f first
#define s second
const int mod = 1e9 + 7;

int n, k, s, e;
ll dp[55][55];

ll rec(int level, int steps_left){
    if(steps_left==0){
        return level == e;
    }
    if(dp[level][steps_left]!=-1){
        return dp[level][steps_left];
    }

    ll ans = 0;
    ans += rec((level+1 == n+1 ? 1: level+1) , steps_left-1);
    ans += rec((level-1) == 0 ? n : level-1, steps_left-1);

    return dp[level][steps_left] =  ans;
}

void solve()
{
    cin>>s>>e;
    SET(dp);
    cout<<rec(s,k)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        while(cin>>n>>k && n!=-1 && k!=-1){
            solve();
        }
    }
    return 0;
}