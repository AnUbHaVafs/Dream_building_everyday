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
const int N = 101;

int n;
int arr[N];
ll dp[N + 1][N + 1];

ll cost(int i, int j, int k)
{
    return (ll)arr[i] * (ll)arr[j] * (ll)arr[k];
}

ll rec(int l, int r)
{
    // pruning
    // cout << l << " " << r << endl;
    // base case
    if (r-l+1 < 3)
        return (ll)0;
    // cache check
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    // compute and transition
    ll ans = inf;
    for (int x = l + 1; x <= r - 1; x++)
    {
        // immediate left traingle
        if (x == l + 1)
        {
            ans = min(ans, cost(l, x, r) + rec(x, r));
        }
        // immediate right traingle
        else if (x == r - 1)
        {
            ans = min(ans, cost(l, x, r) + rec(l, x));
        }
        // splits the polygon into 2
        else
        {
            ans = min(ans, cost(l, x, r) + rec(l, x) + rec(x, r));
        }
    }
    // save and return
    return dp[l][r] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    SET(dp);
    ll ans = rec(1, n);
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