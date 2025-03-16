#include <bits/stdc++.h>
using namespace std;

const int IMIN = -1e8;

int maxStones(vector<vector<int>> &stones, int h, int w)
{
    vector<vector<int>> dp(h, vector<int>(w, IMIN));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0)
            {
                dp[i][j] = stones[i][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (j > 0)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                }
                if (j < w - 1)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
                }
                dp[i][j] += stones[i][j];
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < w; j++)
    {
        ans = max(ans, dp[h - 1][j]);
    }
    return ans;
}

void solve()
{

    int h, w;
    cin >> h >> w;
    vector<vector<int>> stones(h, vector<int>(w, 0));
    // cin.ignore();
    for (int i = 0; i < h; i++)
    {
        // string s;
        // getline(cin,s);
        // for(int x=0,j=0;x<s.size() && j<w;x++){
        //     if(s[x]!=' '){
        //         stones[i][j++] = s[x]-'0';
        //     }
        // }
        for (int j = 0; j < w; j++)
        {
            cin >> stones[i][j];
        }
    }
    cout << maxStones(stones, h, w);
}

int main()
{
    int tt;
    cin >> tt;
    for (int i = 0; i < tt; i++)
    {
        if (i != 0)
            cout << endl;
        solve();
    }
    return 0;
}