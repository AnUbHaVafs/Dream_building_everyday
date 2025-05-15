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

int M, D;
string L, R;
int len;
int dp[2005][2][2][2000][3];

int rec(int level, int tlo, int thi, int numM, int parity)
{
    // cout<<level<<" "<<tlo<<" "<<thi<<" "<<numM<<" "<<parity<<endl;
    // pruning
    // base case
    if (level == len)
    {
        return (numM == 0);
    }

    // cache check
    if (dp[level][tlo][thi][numM][parity] != -1)
    {
        return dp[level][tlo][thi][numM][parity];
    }

    // compute and transitions
    int ans = 0;
    // permissible range
    int lo = 0;
    if (tlo == 1)
    {
        lo = L[level] - '0';
    }
    int hi = 9;
    if (thi == 1)
    {
        hi = R[level] - '0';
    }

    for (int i = lo; i <= hi; i++)
    {
        if (parity == 2 && i != D)
            continue;
        if (parity == 1 && i == D)
            continue;
        if (parity == 0 && i != 0 && i == D)
            continue;
        int ntlo = tlo;
        if (i != L[level] - '0')
            ntlo = 0;
        int nthi = thi;
        if (i != R[level] - '0')
            nthi = 0;
        int nParity = parity == 0 ? (i != 0 ? 2 : 0) : (parity % 2 == 0 ? 1 : 2);

        ans += rec(level + 1, ntlo, nthi, ((numM * 10 + i) % M), nParity);
        ans %= mod;
    }
    // save and return
    return dp[level][tlo][thi][numM][parity] = ans;
}

void solve()
{
    cin >> M >> D;
    cin >> L >> R;
    len = R.length();
    int cnt = R.length() - L.length();
    string temp = "";
    while (cnt--)
    {
        temp += '0';
    }
    L = temp + L;
    SET(dp);
    cout << rec(0, 1, 1, 0, 0) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}