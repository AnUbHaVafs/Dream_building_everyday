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
int n,m,k;
int score[105][105];
int dp[105][105][905];

// max sum possible from  (i,j,sum) till last row if sum of "sum" is already taken.
int rec(int i, int j, int sum){
    if(i==n-1){
        if((sum+score[i][j])%k==0)return sum+score[i][j];
        else return -1;
    }

    // cache check
    if(dp[i][j][sum]!=-1){
        return dp[i][j][sum];
    }
    // compute and transitions
    int ans = -1; // since 0 is the potential answer
    if(j-1>=0){
        ans = max(ans, rec(i+1, j-1, sum + score[i][j]));
    }
    if(j+1<m){
        ans = max(ans, rec(i+1, j+1, sum + score[i][j]));
    }
    // save and return
    return dp[i][j][sum] = ans;
}

void solve(){
    cin>>n>>m>>k;
    CLR(score);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin>>c;
            score[i][j] = c - '0';
        }
    }
    SET(dp);
    int ans = -1;
    for(int i=0; i<m; i++){
        ans = max(ans, rec(0,i,0));
    }
    cout<<ans<<endl;
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