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

const int MAXN = 10;
int n;
vector<int> g[MAXN];
int dp[100][(1<<MAXN)];
bool hasTshirt[MAXN][100];

int rec(int level, int mask){
    // cout<<level<<" "<<mask<<endl;
    if(mask==((1<<n)-1)){
        return 1;
    }
    if(level==100){
        return 0;
    }
    if(dp[level][mask]!=-1){
        return dp[level][mask];
    }

    int ans = 0;
    // don't assign
    ans += rec(level+1, mask);
    // assign (to any person)
    for(int i=0; i<n; i++){ // person has not been assigned any t-shirt yet
        if((mask & (1<<i))==0 && hasTshirt[i][level]){
            ans += rec(level+1, (mask | (1<<i)));
            ans %= MOD;
        }
    }
    return dp[level][mask] = ans;
}

void solve()
{
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++){
        for(int j=0; j<100; j++){
            hasTshirt[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int x;
        while(ss>>x){
            g[i].pb(x-1);
            hasTshirt[i][x-1] = 1;
        }
    }
    // cout<<n<<endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<100; j++){
    //         cout<<hasTshirt[i][j]<<" ";
    //     }
    //     cout<<"-----";
    //     cout<<endl;
    // }
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