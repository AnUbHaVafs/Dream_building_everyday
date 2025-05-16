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

int n;
int arr[101];
int dp[101][101][101];

// rec(0,n-1,k) --> max points possible if from [0..n-1] if k is the length of contiguous
// elements same as arr[l] and just before l.
int rec(int l, int r, int k)
{
    // pruning
    // base case
    if (r < l)
        return 0;
    if (l == r)
        return (k + 1) * (k + 1);
    // cache check
    if (dp[l][r][k] != -1)
    {
        return dp[l][r][k];
    }
    // compute and transitions
    int ans = 0;
    // remove the lth element alone
    ans = max(ans, ((k + 1) * (k + 1)) + rec(l + 1, r, 0));
    // find the next match and merge arr[l]
    for (int mid = l + 1; mid <= r; mid++)
    {
        if (arr[mid] == arr[l])
        {
            ans = max(ans, rec(l + 1, mid - 1, 0) + rec(mid, r, k + 1));
        }
    }
    // save and return
    return dp[l][r][k] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SET(dp);
    int ans = rec(0, n - 1, 0);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}