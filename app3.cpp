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

const ll MAXM = 2*10;
ll pre_gcd[MAXM][MAXM];

ll n, A[MAXM];
ll dp[(1<<(MAXM))];

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); 
     
}

ll rec(int level, int mask){
    if(level==n)return 0;
    if(dp[mask]!=-1){
        return dp[mask];
    }
    ll ans = 0;
    // intraset matching
    for(int i=0; i<2*n; i++){
        for(int j=0; j<2*n; j++){
            if(i==j)continue;
            if((mask & ((1<<i) | (1<<j))) == 0){ // player i, j not assigned
                ans = max(ans, (level+1)*abs(A[i]-A[j])*pre_gcd[i][j] + 
                rec(level+1, mask | ((1<<i) | (1<<j))));
            }
        }
    }
    return dp[mask] = ans;
}

void solve()
{
    cin>>n;
    for(int i=0; i<2*n; i++){
        cin>>A[i];
    }
    for(int i=0; i<2*n; i++){
        for(int j=0; j<2*n; j++){
            pre_gcd[i][j] = gcd(A[i], A[j]);
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