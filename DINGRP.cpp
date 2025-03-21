#include <bits/stdc++.h>
using namespace std;

int K;

// remove boxes
// group algoerithm
// drop G1 and solve for remaining groups
// We can join G1 with G3, G5, ... Gn-1.
// join G1, with [Gm...Gn-1] goeups adding extras + G1.count and also add middle skipped groups [Gi+1,....Gm-1] with extras as 0.

int dp[102][102][102];
int solve(int i, int j, int extra, vector<pair<int, int>> &groups)
{
    if (i > j){
        return 0;
    }
        
    if (i == j)
    {
        if (extra + groups[i].second < K )
        {
            return 1e9;
        }
        else
            return 1;
    }

    if (dp[i][j][extra] != -1){
        return dp[i][j][extra];
    }
    int ans = 1e9;    
    if (extra + groups[i].second >= K ){
        ans = solve(i+1, j, 0, groups) + 1;
    }
        
    // int ans = 1 + solve(i + 1, j, 0, groups);

    for (int g = i + 1; g <= j; g++)
        if (groups[g].first == groups[i].first)
            ans = min(ans, solve(i + 1, g - 1, 0, groups) + solve(g, j, extra + groups[i].second, groups));

    return dp[i][j][extra] = ans;
}
int removeBoxes(vector<int> &boxes)
{
    int n = boxes.size();

    vector<pair<int, int>> groups;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (i + 1 < n and boxes[i + 1] == boxes[j])
            i++;
        groups.push_back({boxes[j], i - j + 1});
    }

    memset(dp, -1, sizeof(dp));
    return solve(0, groups.size() - 1, 0, groups);
}

void solve()
{
    int n,k;
    cin>>n>>k;
    K=k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='G')arr[i]=0;
        else arr[i]=1;
        // cout<<arr[i]<<endl;
    }
    int ans = removeBoxes(arr);
    if(ans>=1e9)cout<<-1;
    else cout<<ans;
}

int main()
{
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
