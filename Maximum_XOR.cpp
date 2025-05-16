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
ll L, R;
string binaryL, binaryR;
ll dp[64][2][2][2][2];

ll rec(int level, int tlo1, int thi1, int tlo2, int thi2)
{
    // pruning
    //  base case
    if (level == len)
    {
        return 0;
    }
    // cache check
    if (dp[level][tlo1][thi1][tlo2][thi2] != -1)
    {
        return dp[level][tlo1][thi1][tlo2][thi2];
    }
    // compute and transitions
    int lo1 = 0;
    if (tlo1 == 1)
    {
        lo1 = binaryL[level] - '0';
    }
    int hi1 = 1;
    if (thi1 == 1)
    {
        hi1 = binaryR[level] - '0';
    }

    int lo2 = 0;
    if (tlo2 == 1)
    {
        lo2 = binaryL[level] - '0';
    }
    int hi2 = 1;
    if (thi2 == 1)
    {
        hi2 = binaryR[level] - '0';
    }

    ll ans = 0;
    for (int i = lo1; i <= hi1; i++)
    {
        for (int j = lo2; j <= hi2; j++)
        {
            int ntlo1 = tlo1;
            if (i != binaryL[level] - '0')
                ntlo1 = 0;
            int nthi1 = thi1;
            if (i != binaryR[level] - '0')
                nthi1 = 0;
            int ntlo2 = tlo2;
            if (j != binaryL[level] - '0')
                ntlo2 = 0;
            int nthi2 = thi2;
            if (j != binaryR[level] - '0')
                nthi2 = 0;

            ll xorForLevel = (1LL << (len - level - 1)) * (i ^ j);
            ans = max(ans, xorForLevel + rec(level + 1, ntlo1, nthi1, ntlo2, nthi2));
        }
    }
    // save and return
    return dp[level][tlo1][thi1][tlo2][thi2] = ans;
}

string getBin(ll num)
{
    string res = "";
    while (num)
    {
        res += ((num & 1) + '0');
        num /= 2;
    }
    if (res == "")
    {
        res = "0";
    }
    else
    {
        reverse(res.begin(), res.end());
    }
    return res;
}

void solve()
{
    cin >> L >> R;
    binaryL = getBin(L);
    binaryR = getBin(R);
    int cnt = binaryR.length() - binaryL.length();
    string temp = "";
    while (cnt--)
    {
        temp += '0';
    }
    binaryL = temp + binaryL;
    len = binaryR.length();
    SET(dp);
    cout << rec(0, 1, 1, 1, 1) << endl;
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