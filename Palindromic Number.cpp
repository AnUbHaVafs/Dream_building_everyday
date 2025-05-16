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
const int BUFFER = 1;

string L, R;
ll len;
ll dp[64][2][2][65][2][2];

ll rec(ll level, int tlo, int thi, int startD, int edone, int odone)
{
    // pruning
    // base case
    if (level == len)
    {
        return (edone && odone);
    }
    if (level > len)
        return 0;
    // cache check
    if (dp[level][tlo][thi][startD + BUFFER][edone][odone] != -1)
    {
        return dp[level][tlo][thi][startD + BUFFER][edone][odone];
    }
    // compute and transitions
    ll lo = 0;
    if (tlo == 1)
    {
        lo = L[level] - '0';
    }
    ll hi = 9;
    if (thi == 1)
    {
        hi = R[level] - '0';
    }
    ll ans = 0;
    for (ll i = lo; i <= hi; i++)
    {
        int nStartD = startD;
        if (startD == -1 && i != 0)
        {
            nStartD = i;
        }
        int nEDone = edone;
        int nODone = odone;
        int ntlo = tlo;
        if (i != L[level] - '0')
            ntlo = 0;
        int nthi = thi;
        if (i != R[level] - '0')
            nthi = 0;

        if (startD != -1)
        {
            for (ll cnt = 1; cnt <= (level - startD + 1); cnt++)
            {
                // even len palindromes
                ans += rec(level + cnt + 1, ntlo, nthi, startD, 1, nODone);
                // odd len palindromes
                if (cnt != (ll)1)
                {
                    ans += rec(level + cnt, ntlo, nthi, startD, nEDone, 1);
                }
            }
        }
        ans = ans + rec(level + 1, ntlo, nthi, nStartD, nEDone, nODone);
    }
    // save and return
    return dp[level][tlo][thi][startD + BUFFER][edone][odone] = ans;
}

void solve()
{
    cin >> L >> R;
    len = R.length();
    ll cnt = R.length() - L.length();
    string temp = "";
    while (cnt--)
    {
        temp += '0';
    }
    L = temp + L;
    SET(dp);
    cout << rec(0, 1, 1, -1, 0, 0) << endl;
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