#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int m, n;
vector<vector<int>> Candies;
vector<int> rows;
vector<vector<int>> dp;

// find max candies we can take if prev is taken or not_taken from [level...N-1].
int rec(int level, bool prev, vector<int> &candies){ 
    int N = candies.size();
    if(level==N){
        return 0;
    }
    // cache check
    if(dp[level][prev]!=-1){
        return dp[level][prev];
    }

    int ans = 0;
    if(!prev){
        ans = max(ans, candies[level] + rec(level+1, true, candies));
    }
    ans = max(ans, rec(level+1, false, candies));

    return dp[level][prev] = ans;
}

void solve()
{
    vector<vector<int>> newCandies(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>newCandies[i][j];
        }
    }
    Candies = newCandies;
    // max. no. of candies we can pick in each row
    vector<int> newRows(m,0);
    rows = newRows;

    for(int i=0; i<m; i++){
        vector<vector<int>> newDp(n+1, vector<int>(2, -1));
        dp = newDp;
        newRows[i] = rec(0, false, newCandies[i]);
        // cout<<newRows[i]<<endl;
    }
    vector<vector<int>> newDp(m + 1, vector<int>(2, -1));
    dp = newDp;
    cout<< rec(0, false, newRows) <<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        while(cin>>m>>n && m!=0 && n!=0){
            solve();
        }
    }
    return 0;
}