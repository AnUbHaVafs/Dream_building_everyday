#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int hours[125];
int dp[125];

int rec(int level)
{ 
    if(level>=n-1){
        return 0;
    }

    if(dp[level]!=-1){
        return dp[level];
    }
    
    int ans = 0;
    int taken = 0;
    for(int i=level; i<n; i++){
        taken += hours[i];
        int mine = 0;
        for(int pos = i+1; pos<n && mine + hours[pos] < taken; pos++){
            mine += hours[pos];
            ans = max(ans, mine + rec(pos+1));
        }
    }
    return dp[level] = ans;
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
    int myHours = rec(0);
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