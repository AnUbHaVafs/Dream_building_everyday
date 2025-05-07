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
const int mod = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;

int n, m;
string s, t;
int pre[1001][1001];
int dp[1001][1001];

int rec(int i, int j){ // min. len of subsq. from s[0..i] which is not in t[0...j] as a subsq.
    if(i==-1)return inf;
    if(j==-1)return 1;

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = inf;
    // skip
    ans = rec(i-1, j);
    // take it as part of subsquence
    // if not found 
    if(pre[i][j]==-1)ans = 1;
    else{
        ans = min(ans, 1 + rec(i-1, pre[i][j] - 1));
    }

    return dp[i][j] = ans;
}

void solve()
{
    cin>>s>>t;
    n = s.length(), m = t.length();
    memset(dp, -1, sizeof(dp));
    memset(pre, -1, sizeof(pre));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i]==t[j])pre[i][j] = j;
        }
    }
    int ans = rec(n - 1, m - 1);
    if (ans > n)ans = -1;
    cout << ans << endl;
    // dp[i][j] --> min. len subsq from [0..i] which is not present as subsq in t[0..j].
    
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