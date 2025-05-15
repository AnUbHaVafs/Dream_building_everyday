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
const int mod = 1e9+7;
const int inf = 1e9;
const ll INF = 1e18;

ll len;
string L,R;
int D;
ll dp[10010][2][2][100];

ll rec(int level, int tlow, int thi, int sumD){
    // pruning
    // base case
    if((ll)level==len){
        return (sumD==0);
    }
    // cache check
    if(dp[level][tlow][thi][sumD]!=-1){
        return dp[level][tlow][thi][sumD];
    }
    // compute and transitions
    ll ans = 0;
    // for this node (at level) find which type of node it is and hence it's corresponding l and r.
    // permissible values
    int lo = 0;
    if(tlow==1){
        lo = L[level]-'0';
    }
    int hi = 9;
    if(thi==1){
        hi = R[level] - '0';
    }
    for(int i=lo; i<=hi; i++){
        // find now which type of node it will be amongst 4.
        int ntlo = tlow;
        if(i!=L[level]-'0')ntlo = 0;

        int nthi = thi;
        if(i!=R[level]-'0')nthi = 0;

        ans = (ans + rec(level+1, ntlo, nthi, (sumD+i)%D))%mod;
    }
    // save and return
    return dp[level][tlow][thi][sumD]=ans;
}

void solve()
{
    L = "1";
    cin>>R;
    cin>>D;
    ll cnt = R.length() - L.length();
    string temp = "";
    while(cnt--){
        temp += '0';
    }
    L = temp + L;
    len = R.length();

    SET(dp);
    cout<<rec(0,1,1,0)<<endl;    
}

int main()
{
    IOS
    int tt=1;
    // cin >> tt;  
    while (tt--)
    {
        solve();
    }
    return 0;
}