#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int m,n,k;
int dp[221][11][221];

int rec(int num, int n, int prev){
    if(prev>num){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(dp[num][n][prev]!=-1){
        return dp[num][n][prev];
    }

    int ans=0;
    for(int i=prev; i<=num/2; i++){
        ans += rec(num-i, n-1, i);
    }
    return dp[num][n][prev] = ans;
}

void solve()
{
    cin>>m>>n>>k;
    memset(dp,-1,sizeof(dp));
    // but I need the kth lexicographical partition
    // use below appraoch
    int curr = 1;
    for(int i=1;i<n;i++){ // till the second last number we  find number and last no = remaining sum
        while(rec(m-curr, n-i, curr)<k){
            k -= rec(m-curr, n-i, curr);
            curr++;
        }
        cout<<curr<<" ";
        m -= curr;
    }
    cout << m << endl;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
