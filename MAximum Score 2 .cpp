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

int dp[101][101][12];
int a[101][101];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    memset(dp, -1, sizeof(dp));
    for (int j = 1; j <= m; j++)
    {
        int t = a[n][j] % k;
        dp[n][j][t] = a[n][j];
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int l = 0; l < k; l++)
            {
                if (j - 1 > 0 && dp[i + 1][j - 1][l] >= 0)
                {
                    int t = dp[i + 1][j - 1][l] + a[i][j];
                    if (dp[i][j][t % k] < t)
                    {
                        dp[i][j][t % k] = t;
                    }
                }

                if (j < m && dp[i + 1][j + 1][l] >= 0)
                {
                    int t = dp[i + 1][j + 1][l] + a[i][j];
                    if (dp[i][j][t % k] < t)
                    {
                        dp[i][j][t % k] = t;
                    }
                }
            }
        }
    }
    int ans = -1;
    for (int j = 1; j <= m; j++)
    {
        // cout<<"heer--> "<<dp[1][j][0]<<endl;
        ans = max(ans, dp[1][j][0]);
    }
    cout << ans << "\n";
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