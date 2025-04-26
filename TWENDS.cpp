#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define pii pair<int, int>
#define psi pair<string, int>
#define f first
#define s second
const int mod = 1e9 + 7;

int n;
int v[2005];
int dp[2005][2005][2];

int rec(int i, int j, int playerTurn)
{
    if(i==j){
        return 0;
    }

    // cache check
    if(dp[i][j][playerTurn]!=-1){
        return dp[i][j][playerTurn];
    }

    int ans = 0;
    if(playerTurn==1){
        ans = max(ans, v[i] + rec(i+1,j,2));
        ans = max(ans, v[j] + rec(i,j-1,2));
    }
    else{
        if(v[i]<v[j]){
            ans = max(ans,rec(i,j-1,1));
        }
        else{
            ans = max(ans,rec(i+1,j,1));
        }
    }
    return dp[i][j][playerTurn] = ans;
}

void solve(int cnt)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    SET(dp);
    int p1 = rec(0, n-1, 1);
    int p2 = sum-p1;
    cout<<"In game "<<cnt<<", the greedy strategy might lose by as many as "<<abs(p1-p2)<<" points."<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        int cnt=1;
        while (cin >> n && n!=0)
        {
            solve(cnt);
            cnt++;
        }
    }
    return 0;
}