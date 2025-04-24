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

int cs, R, C;
char grid[101][101];
int f[200][100][100], dp[200][100][100];

int rec(int steps, int r1, int r2){
    // base case
    if(steps==R+C-2){
        if(steps-r1==C-1 && r1==R-1 && r1==r2){
            return grid[R-1][C-1] == '*';
        }
        else{
            return -1;
        }
    }
    if(f[steps][r1][r2]==cs){
        return dp[steps][r1][r2];
    }

    int ans = -1; // no valid moves left for both persons
    int c1 = steps-r1, c2 = steps-r2;
    if(c1>=0 && c2>=0 && c1<C && c2<C && grid[r1][c1]!='#' && grid[r2][c2]!='#'){
        ans = max(ans, rec(steps+1, r1, r2));
        if(r1+1<R){
            ans = max(ans, rec(steps+1, r1+1, r2));
        }
        if(r2+1<R){
            ans = max(ans, rec(steps+1, r1, r2+1));
        }
        if(r1+1<R  && r2+1<R){
            ans = max(ans, rec(steps+1, r1+1, r2+1));
        }
        if(ans!=-1){
            if(grid[r1][c1]=='*')ans++;
            if(r1!=r2 && grid[r2][c2]=='*')ans++;
        }
    }
    f[steps][r1][r2] = cs;
    return dp[steps][r1][r2] = ans;
}

void solve()
{
    cin>>C>>R;
    for(int i=0; i<R; i++){
        cin>>grid[i];
    }
    cout<<rec(0,0,0)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for(cs=1; cs<=tt; cs++){
        solve();
    }
    return 0;
}