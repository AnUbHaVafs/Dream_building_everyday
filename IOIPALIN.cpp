#include<bits/stdc++.h>
using namespace std;

int N;
string s1,s2;
int dp[5001][5001];

int rec(int i, int j){
    // pruning
    // base case
    if(i==N || j==N){
        return 0;
    }
    // caching
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    // compute and transition
    int ans=0;
    if(s1[i]==s2[j]){
        ans = max(ans, 1 + rec(i+1,j+1));
    }
    else {
        ans = max(ans, max(rec(i+1,j), rec(i,j+1)));
    }
    // save and return;
    return dp[i][j] = ans;
}

void solve(){
    cin>>N;
    cin>>s1;
    s2 = s1;
    reverse(s2.begin(),s2.end());
    memset(dp,-1,sizeof(dp));
    int lcs = rec(0,0); 
    cout<<(N-lcs)<<endl;   
}

int main(){
    int tt=1;
    while(tt--){
        solve();
    }
    return 0;
}