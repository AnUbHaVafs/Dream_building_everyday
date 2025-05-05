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
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;

int n;
double arr[3001];
double dp[3001][3001];

double rec(int level, int heads){

    if(level==n){
        return ((heads > (n / 2)) ? 1.0 : 0.0);
    }

    if(dp[level][heads] != -1.0){
        return dp[level][heads];
    }

    double ans = 0.0;
    ans += arr[level]*rec(level+1, heads+1);
    ans += (1.0-arr[level])*rec(level+1, heads);
    return dp[level][heads] = ans;
}

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<3001; i++){
        for(int j=0; j<3001; j++){
            dp[i][j] = -1.0;
        }
    }
    cout<<setprecision(9)<<rec(0,0)<<endl;
}

int main()
{
    IOS
    int tt = 1;
    // cin >> tt;  
    while (tt--)
    {
        solve();
    }
    return 0;
}