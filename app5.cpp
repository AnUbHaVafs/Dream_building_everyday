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
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD = 1e9+7;
const int INF = 1e9;
const ll LLINF = 1e18;

// Learnings: 
// Problem specific:
// How to think?
// 1. think of last cell to place a domino at(curr call -> (i,j)) -> rec(i,j)= no. of ways to tile from (i,j) to (n-1, m-1) given mask visited.
// 2. At curr cell to place 2X1 or 1X2 we only need to know the top bit ((i-1,j) = 0-index in mask) and left bit ((i,j-1) = m-1th index in mask) we kind of maintain the sliding bitmask for every cell and for last m-cells in mask.
// 3. We cover the cases like for last_col, go to next_row, first_col and others checks.

// Coding logic(tiling/profile dp):
// 1. At first cell, (i,0) you cannot place horizontal domino.
// 2. When u create ni, nj consider both cases j+1==m(i+1,0) and default case(i,j+1)
// 3. To start with and end with(base case), set all m-length mask to 1, whose value would be (1<<m)-1.

// What we learn in general:
// 1.What to mask depends upon-> on whose cells my curr cell value is depend upon.
// in this case, we use sliding bitmask of size m.
// in some other question it would be trickier.

const int MAXN = 12;

int n,m;
ll dp[MAXN][MAXN][(1<<MAXN)];

ll rec(int i, int j, int mask){
    if(i==n){
        if(mask==((1<<m)-1)){
            // cout<<i<<" "<<j<<" "<<mask<<endl;
            return (ll)1;
        }
        else return (ll)0;
    }
    if(dp[i][j][mask]!=-1){
        return dp[i][j][mask];
    }
    int ni = i, nj = j;
    if(j+1==m){
        ni = i + 1;
        nj = 0;
    }
    else{
        ni = i;
        nj = j+1;
    }
    ll ans = 0;
    // case 1
    if((mask&1)==0){
        // 1 trans.
        int new_mask = ((mask>>1) | (1<<m-1)); // remove the top bit and set new MSB;
        ans += rec(ni, nj, new_mask); // handle edge cases
    }
    else if((mask & (1<<m-1)) == 0){
        // 2 trans.
        // close it
        if(j>0){
            ans += rec(ni, nj, (mask>>1) | (1<<m-1) | (1<<m-2));
        }
        // left open
        ans += rec(ni, nj, mask>>1);
    }
    else{
        // left open: no pairing can be done here
        ans += rec(ni, nj, mask>>1);
    }
    // cout<<ans<<endl;
    return dp[i][j][mask] = ans;
}

void solve()
{
    cin>>n>>m;
    SET(dp);
    cout<<rec(0,0,(1<<m)-1)<<endl;
}

int main()
{
    IOS
    int tt;
    cin >> tt;  
    while (tt--)
    {
        solve();
    }
    return 0;
}