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

string s, t;
int n, m;
int dp[1001][1001];

int rec(int i, int j){
    if(i==n || j==m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = 0;
    if(s[i]==t[j]){
        ans = max(ans, 1 + rec(i+1, j+1));
    }
    else{
        ans = max(rec(i+1,j), rec(i, j+1));
    }
    return dp[i][j] = ans;
}

string reverse1(string s1){
    string s2 = "";
    for(int i=s1.size()-1; i>=0; i--){
        string s3(1, s1[i]);
        s2 += s3;
    }
    return s2;
}

void solve()
{
    cin>>s;
    t = reverse1(s);
    // cout<<s<<" "<<t<<endl;
    n = s.length(), m = t.length();
    SET(dp);
    int lcsLen = rec(0,0);
    int ans = n-lcsLen;
    cout<<ans<<endl;

}

int main()
{
    IOS
    int tt;
    cin >> tt;  
    while (tt--)
    {
        solve();
    }
    return 0;
}