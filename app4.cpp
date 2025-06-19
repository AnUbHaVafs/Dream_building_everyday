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
const int MAXN = 15;

int n;
bool isEdge[MAXN][MAXN];
ll dp[(1<<MAXN)];

ll rec(int mask){
    int pos = __builtin_popcount(mask);
    if(pos==n)return 0;
    if(dp[mask]!=-1){
        return dp[mask];
    }
    // try to place any edge i which is not vis
    ll ans = 2e18;
    for(int i=0; i<n; i++){
        if((mask&(1<<i))==0){
            int cost = 0;
            for(int j=0; j<n; j++){
                // backward edge
                if((mask & (1<<j)) != 0){
                    cost+=isEdge[i][j];
                }
            }
            ans = min(ans, (ll)cost + rec(mask | (1<<i)));
        }
        
    }
    return dp[mask] = ans;
}

void solve()
{
    cin>>n;
    // Consider nodes are from 0,1,2,3...
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>isEdge[i][j];
        }
    }
    SET(dp);
    cout<<rec(0)<<endl;
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