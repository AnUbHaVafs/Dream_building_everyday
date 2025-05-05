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

// count distinct subsqs of s
// DISTINCT --> means use "prev occurence of char"
// dp(i) = sum(i-1) + sum(last(s)-1);

void solve()
{
    int n;
    string s;
    cin>>s;
    n = s.length();
    int dp[n+1]; // distinct subsq ending at i
    int sum[n+1]; // total distinct subsq count till i
    dp[0]=1; // ""
    sum[0]=1; // ""->1
    int last[26];
    memset(last, 0, sizeof(last));
    for(int i=1; i<=n; i++){
        dp[i] = sum[i-1];
        if(last[s[i-1]-'a']>0){
            dp[i] -= sum[last[s[i-1]-'a']-1];
        }
        sum[i] = sum[i-1] + dp[i];
        last[s[i-1]-'a'] = i;
    }
    cout<<sum[n]<<"\n";
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