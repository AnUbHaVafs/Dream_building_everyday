#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int hours[101];
int dp[101][100001][2];

// TLE code

int rec(int level, int prev_hours, int turn)
{ // my max. work hours [level...N-1] given turn with prev_hours
    if (level == n)
    {
        return 0;
    }

    if (dp[level][prev_hours][turn] != -1)
    {
        return dp[level][prev_hours][turn];
    }

    int ans = 0;
    // I assigned work to myself
    if (prev_hours - hours[level] > 0)
    {
        ans = max(ans, hours[level] + rec(level + 1, prev_hours - hours[level], 1));
    }
    // Lignates took this work hours
    // Same Turn/Cycle
    if (turn == 0)
    {
        ans = max(ans, rec(level + 1, prev_hours + hours[level], 0));
    }
    // New Turn/Cycle
    if (turn == 1)
    {
        ans = max(ans, rec(level + 1, hours[level], 0));
    }

    return dp[level][prev_hours][turn] = ans;
}

void solve()
{
    cin >> n;
    int totalHours = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> hours[i];
        totalHours += hours[i];
    }
    memset(dp, -1, sizeof(dp));
    int myHours = rec(0, 0, 0);
    cout << totalHours - myHours << " " << myHours << endl;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}