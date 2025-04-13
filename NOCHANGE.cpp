#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int k;
int dp[6][100005];

void solve()
{
    cin >> n;
    cin >> k;
    int coins[k];
    for (int i = 0; i < k; i++)
    {
        cin >> coins[i];
    }
    memset(dp, 0, sizeof(dp));
    int cnt = 0;
    for (int i = coins[0]; i <= n; i += coins[0])
    {
        cnt++;
        dp[0][i] = cnt;
    }

    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cnt = 0;
            int p = dp[i - 1][j];
            while (p)
            {
                cnt++;
                dp[i][j + (cnt * coins[i])] = max(dp[i][j + (cnt * coins[i])], cnt);
                p--;
            }
        }
    }
    bool found = false;
    for (int i = 0; i < k; i++)
    {
        if (dp[i][n])
        {
            cout << "YES";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "NO";
    }
}

int main()
{
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        // while(cin>>n){
        solve();
        // }
    }
    return 0;
}
