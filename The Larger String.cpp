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

int len;
string L, R;
int dp[100010][2][2][2];

int rec(int level, int tlo, int thi, int differ)
{
    // pruning
    // base case
    if (differ == 1)
        return 1;
    if (level == len)
    {
        // return 1;
        return (differ == 1);
    }
    // cache check
    if (dp[level][tlo][thi][differ] != -1)
    {
        return dp[level][tlo][thi][differ];
    }
    // compute and transitions
    int ans = 0;
    char lo = 'A';
    if (tlo == 1)
    {
        lo = L[level];
    }
    char hi = 'Z';
    if (thi == 1)
    {
        hi = R[level];
    }
    for (char i = lo; i <= hi; i++)
    {
        int ntlo = tlo;
        if (i != L[level])
            ntlo = 0;
        int nthi = thi;
        if (i != R[level])
            nthi = 0;
        if (i > L[level])
        {
            ans += rec(level + 1, ntlo, nthi, 1);
        }
        ans += rec(level + 1, ntlo, nthi, 0);
        ans %= mod;
    }
    // save and return
    return dp[level][tlo][thi][differ] = ans;
}

void solve()
{
    cin >> L;
    len = L.length();
    string temp = "";
    for (int i = 0; i < len; i++)
    {
        temp += 'Z';
    }
    R = temp;
    SET(dp); // iterate over this rather than SET.
    cout << rec(0, 1, 1, 0) << endl;
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