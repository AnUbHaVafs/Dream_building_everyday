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
int v[2005];
int dp[2005][2005];
// 0 1 2 3 4 5

int rec(int i, int age){
    int j = (n-1) - (age-(i+1));
    if(i==j){
        return age*v[i];
    }

    if(dp[i][age]!=-1){
        return dp[i][age];
    }

    int ans = 0;
    ans = max(ans, (age*v[i]) + rec(i+1, age+1));
    ans = max(ans, (age*v[j]) + rec(i, age+1));
    return dp[i][age] =  ans;
}

void solve()
{
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    SET(dp);
    cout<<rec(0,1)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        while(cin>>n){
            solve();
        }
    }
    return 0;
}