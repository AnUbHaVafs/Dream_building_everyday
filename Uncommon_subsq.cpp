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

const int inf = 1e9;
// TC = O(N*M*M); -- TLE
string s, t;
int n, m;
int dp[1001][100];

int rec(int i, int j)
{
    if (i == n)
        return inf;
    if (j == m)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = inf;

    // Option 1: skip S[i]
    ans = min(ans, rec(i + 1, j));

    // Option 2: take S[i]
    int k = j;
    while (k < m && t[k] != s[i])
        k++;

    if (k == m)
    {
        // S[i] is not in T[j:], so this character alone is a valid answer
        ans = min(ans, 1);
    }
    else
    {
        // S[i] found at T[k], take it and move both pointers
        ans = min(ans, 1 + rec(i + 1, k + 1));
    }

    return dp[i][j] = ans;
}

void solve()
{
    cin >> s >> t;
    n = s.length();
    m = t.length();
    SET(dp);
    int ans = rec(0, 0);
    if (ans == inf)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << ans << endl;
    }
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