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

int n;
int turtles[20][3];
int dp[100][3];

int rec(int level, int prev){
    if(level==n){
        return 0;
    }
    if(dp[level][prev]!=-1){
        return dp[level][prev];
    }
    int ans = 1e9;
    for(int i=0; i<=2; i++){
        if(i!=prev){
            ans = min(ans, turtles[level][i] + rec(level+1, i));
        }
    }
    return dp[level][prev] = ans;
}

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin >> turtles[i][0] >> turtles[i][1] >> turtles[i][2];
    }
    SET(dp);
    cout<<rec(0,3)<<endl;
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