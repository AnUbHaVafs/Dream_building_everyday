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

int n;
ll fc[10009], ifc[10009], dp[103][10009];
int d[110];

ll rec(int level, int len){
    if(level==n){
        return len ? fc[len] : 0;
    }
    // cache check
    if(dp[level][len]!=-1){
        return dp[level][len];
    }

    ll ans=0;
    for(int i=0;i<=d[level];i++){
        ans = (ans + ((rec(level+1, len+i)*ifc[i]) % mod))%mod;
    }
    return dp[level][len] = ans;
}

// using computations of [x^n in log(n)] and using [Fermat's little theorem] :
// if p is prime number then: 
// (a)^-1 ! % p == (a)^(p-2) % p;
ll pw(ll b){
    ll r = 1;
    int p = mod-2;
    while(p){
        if(p&1){
            r= (r*b)%mod;
        }
        b = (b*b)%mod;
        p>>=1;
    }
    return r;
}

void solve()
{
    for(int i=0;i<n;i++){
        cin>>d[i];
    }    
    SET(dp);
    cout<<rec(0,0)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        int cnt=1;
        fc[0] = ifc[0] = 1;
        for (int i = 1; i <= 10000; i++)
        {
            fc[i] = (fc[i - 1] * i) % mod;
            ifc[i] = pw(fc[i]);
        }
        while(cin>>n){
            cout<<"Case "<<cnt<<": ";
            solve();
            cnt++;
        }
    }
    return 0;
}