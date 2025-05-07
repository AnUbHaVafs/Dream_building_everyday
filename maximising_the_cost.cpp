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
const ll inf = 1e18;

string s;
int n, k;
int M;
int cost[26][26];
ll dp[102][102][26];
bool vis[102][101][26];

ll rec(int level, int k, char prevChar)
{
    // pruning
    // base case
    if (level == 0)
        return (ll)0;

    // cache check
    if (vis[level][k][prevChar - 'a'])
    {
        return dp[level][k][prevChar - 'a'];
    }
    // compute and transition
    ll ans = -inf;
    // don't change
    ll dontChangeCost = (level == n) ? (ll)0 : (ll)cost[s[level - 1] - 'a'][prevChar - 'a'];
    ans = max(ans, dontChangeCost + rec(level - 1, k, s[level - 1]));

    // change
    if (k > 0 || level == n)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            ll changeCost = (level == n) ? (ll)0 : (ll)cost[c - 'a'][prevChar - 'a'];
            if (c != s[level - 1])
            {
                ans = max(ans, changeCost + rec(level - 1, k - 1, c));
            }
        }
    }
    // save and return
    dp[level][k][prevChar - 'a'] = ans;
    vis[level][k][prevChar - 'a'] = true;
    return ans;
}

void solve()
{
    cin >> s >> k;
    n = s.length();
    cin >> M;
    CLR(cost);
    for (int i = 0; i < M; i++)
    {
        char x, y;
        int c;
        cin >> x >> y >> c;
        cost[x - 'a'][y - 'a'] = c;
    }
    for (int i = 0; i < 102; i++)
    {
        for (int j = 0; j < 102; j++)
        {
            for (int k = 0; k < 26; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    ll ans = -inf;
    for (char c = 'a'; c <= 'z'; c++)
    {
        ans = max(ans, rec(n, k, c));
    }
    cout << ans << endl;
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