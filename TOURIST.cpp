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

int w,h;
string grid[101];
int dp[101][101];
bool vis[101][101];
int ANS = 0;
unordered_set<int> unique_sums;

int rec(int i, int j){
    // cout<<grid[i][j]<<" ";
    // cout << i << " " << j << endl;
    if(i==h-1 && j==w-1){
        return 0;
    }
    if(grid[i][j]=='#'){
        return -1e8;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = 0;
    if(j+1<w){
        ans = max(ans, (vis[i][j] ? 0 :(grid[i][j] == '*')) + rec(i, j + 1));
    }
    if(i+1<h){
        ans = max(ans, (vis[i][j] ? 0 : (grid[i][j] == '*')) + rec(i + 1, j));
    }

    return dp[i][j] = ans;
}

void markMaxPath(int i, int j, int &ans){
    // cout<<"ANS -> "<<ans<<endl;
    if(i==h-1 && j==w-1){
        return;
    }
    if(grid[i][j]=='#'){
        return;
    }
    if(i || j){
        vis[i][j] = true;
    }
    int isInterestingLoc = (grid[i][j] == '*');
    if(j+1<w){
        // cout << "right->" << isInterestingLoc + rec(i, j + 1) <<endl;
        if(ans == isInterestingLoc + rec(i, j + 1)){
            ans = ans - isInterestingLoc;
            // cout<<"hello";
            markMaxPath(i, j+1,ans);
        }
    }
    if(i+1<h){
        // cout<<"bottom"<<endl;
        if(ans == isInterestingLoc + rec(i + 1, j)){
            ans = ans - isInterestingLoc;
            markMaxPath(i+1, j, ans);
        }
    }
    return;
}

void solve()
{
    cin>>w>>h;
    for(int i=0; i<h; i++){
        cin>>grid[i];
    }

    SET(dp);
    ANS = rec(0,0);
    cout<<ANS<<endl;

    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            vis[i][j] = false;
        }
    }

    markMaxPath(0,0,ANS);
    
    SET(dp);
    int roundBackAns = rec(0,0);
    cout<<roundBackAns<<endl;
    markMaxPath(0,0,roundBackAns);
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout<<(vis[i][j] ? 1: 0)<<" ";
        }
        cout<<endl;
    }
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