#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int n;
string s;
int sweet[201];
int dp[205][205];

int rec(int l, int r){
    if(r<l)return 0;
    if(l==r){
        return s[l]=='1';
    }

    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    // if [l...r] has more sweet than sour return else break this [l..r] into subproblems to find max. len that can be sold
    // prefixCount for sweet and sour
    int sweets = sweet[r]-(l==0 ? 0 : sweet[l-1]);
    int sours = (r-l+1) - sweets;
    if(sweets > sours){
        return (r-l+1);
    }

    int ans = 0;
    for(int m=l; m<=r-1; m++){
        ans = max(ans, rec(l,m) + rec(m+1,r));
    }

    return dp[l][r] = ans;
}

void solve()
{
    cin>>n;
    cin>>s;
    memset(sweet,0,sizeof(sweet));
    for(int i=0; i<n; i++){
        if(i>0){
            sweet[i] = (sweet[i-1] + ((s[i]=='1') ? 1 : 0));
        } 
        else{
            sweet[i] = (s[i]=='1');
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}