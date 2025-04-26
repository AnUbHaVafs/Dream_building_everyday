#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

int dp[6][111][111];
int done[6][111][111];
int a[222];
int n, k;

// [L...R] / interval dp
int solve(int r, int from, int to)
{
    if (from > to)
        return 0;
    if (from == to)
        return k - r - 1;

    if (done[r][from][to])
        return dp[r][from][to];
    done[r][from][to] = 1;

    int ans = INF;

    // If current group can vanish
    if (r == k - 1)
    {
        ans = solve(0, from + 1, to);
    }
    else
    {
        ans = solve(r + 1, from, to) + 1; // insert one marble to increase r
    }

    // Try matching same colors later
    for (int i = from + 1; i <= to; i++)
    {
        if (a[i] == a[from])
        {
            int temp = solve(0, from + 1, i - 1) + solve(min(r + 1, k - 1), i, to);
            ans = min(ans, temp);
        }
    }

    return dp[r][from][to] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << solve(0, 0, n - 1) << "\n";

    return 0;
}
