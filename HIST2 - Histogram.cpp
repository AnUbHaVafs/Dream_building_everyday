#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define pii pair<int, int>
#define ALL(x) (x).begin(), (x).end()
#define psi pair<string, int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD = 1e9+7;
const int INF = 1e9;
const ll LLINF = 1e18;

void setIO(string s)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int MAXN = 15;
int n, a[MAXN];
int dp[101][(1<<MAXN)];
int perm[101][(1<<MAXN)];

int rec(int level, int prevh, int mask){ // level->posn, mask->rectangles
    if(level==n){
        perm[prevh][mask] = 1;
        return prevh;
    }
    if(dp[prevh][mask]!=-1){
        return dp[prevh][mask];
    }
    int ans = 0, bestAns = 0;
    for(int i=0; i<n; i++){ // heights are 0-based index and contribution (recc reln is based on 1-based index)
        if((mask & (1<<i))==0){
            ans = max(ans, (abs(a[i]-prevh) + 2) + rec(level+1, a[i], (mask | (1<<i))));
            if(ans>bestAns){
                bestAns = ans;
                perm[prevh][mask] = 0;
            }
            if(ans==bestAns){
                perm[prevh][mask] += perm[a[i]][mask | (1<<i)];
            }
        }
    }
    return dp[prevh][mask] = ans;
}

void solve()
{
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    SET(dp);
    int ans = 0, bestAns = 0, cnt = 0;
    for(int i=0; i<n; i++){
        int val = rec(1, a[i], (1<<i));
        if (val > bestAns)
        {
            bestAns = val;
            cnt = 0;
        }
        if (val == bestAns)
        {
            cnt += perm[a[i]][(1<<i)];
        }
    }
    cout<<bestAns<<" "<<cnt<<endl;
}

int main()
{
    IOS
    // int tt;
    // cin >> tt;  
    while (cin>>n && n!=0)
    {
        solve();
    }
    return 0;
}