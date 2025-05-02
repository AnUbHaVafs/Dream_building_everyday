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
int N;
int arr[501];
int dp[505][505];

// rec(l,r) --> min Cost to merge [l...r]
int rec(int l, int r){
    // cout<<l<<" "<<r<<" "<<endl;
    // base case
    if(l==r){
        return 0;
    }
    // cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    // compute and transitions
    int ans = 1e9;
    int total = 0;
    for(int i=l; i<=r; i++){
        total += arr[i];
    }
    int sum=0;
    for(int m=l; m<r; m++){
        sum+=arr[m];
        // cout<<l<<" "<<m<<" "<<rec(l,m)<<" "<<sum<<endl;
        // cout<<m+1<<" "<<r<<" "<<rec(m+1,r)<<" "<<(total-sum)<<endl;
        // cout<<(sum*(total-sum))%100 <<endl;
        ans = min(ans, rec(l,m) + rec(m+1,r) + (sum*(total-sum))%100);
    }
    // cout<<l<<" "<<r<<" "<<ans<<endl;
    return dp[l][r] = ans;
}

void solve()
{
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    SET(dp);
    cout<<rec(0,N-1)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}