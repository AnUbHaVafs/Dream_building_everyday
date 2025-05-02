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
string x,y;
int n ,m;
int dp[3005][3005];
int back[3005][3005];

int rec(int i, int j){
    if(i==n || j==m){
        return 0;
    }
    // cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = 0;
    if(x[i]==y[j]){
        if(1 + rec(i+1, j+1) > ans){
            ans = max(ans, 1 + rec(i+1, j+1));
            back[i][j]=0;
        }
    }
    else{
        ans = max(rec(i+1,j), rec(i, j+1));
        if(rec(i+1,j)>=rec(i,j+1)){
            back[i][j] = 1;
        }
        else{
            back[i][j] = 2;
        }
    }
    return dp[i][j] = ans;
}

string lcs = "";

void generate(int i, int j){
    if(i==n || j==m){
        return;
    }
    if(back[i][j]==0){
        lcs += x[i];
        generate(i+1,j+1);
    }
    else if(back[i][j]==1){
        generate(i+1,j);
    }
    else{
        generate(i,j+1);
    }
    return;
}



void solve()
{
    cin>>x>>y;
    n = x.length(), m = y.length();
    // cout<<"he";
    SET(dp);
    SET(back);
    rec(0,0);
    generate(0,0);
    cout<<lcs<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        // while(cin>>x && cin>>y){
            solve();
        // }
    }
    return 0;
}