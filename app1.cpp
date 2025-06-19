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

const int MAXM = 55;
const int MAXN = 15;
int N,M;
int happ[MAXM][MAXN];
int dp[MAXM][(1<<MAXN)];

// ranks -> mask
int rec(int level, int rankMask){
    if(level==M)return 0;
    if(dp[level][rankMask]!=-1){
        return dp[level][rankMask];
    }
    int ans = 0;
    // don't assign any rank
    ans = max(ans, rec(level+1, rankMask));
    for(int j=0; j<N; j++){
        if((rankMask & (1<<j))==0){
            ans = max(ans, happ[level][j] + rec(level+1, rankMask | (1<<j)));
        }
    }
    return dp[level][rankMask] = ans;
}

void solve()
{
    cin>>N>>M;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin>>happ[i][j];
        }
    }
    SET(dp);
    cout<<rec(0,0)<<endl;
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