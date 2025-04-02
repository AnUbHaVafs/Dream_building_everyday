#include <bits/stdc++.h>
using namespace std;

int n;
string a,b;
int dp[1001][1001][2];

bool similarRegion(int i, int j){
    return abs(a[i]-b[j])<=1;
}

int rec(int i, int j, bool match){
    if(i==n || j==n){
        return 0;
    }
    if(dp[i][j][match]!=-1){
        return dp[i][j][match];
    }
    int ans=0;
    // if prev match found return max len of matching consecutive substring with i-1,j-1 as prev.
    if(match){
        if(similarRegion(i,j)){
            ans = 1 + rec(i+1,j+1,true);
        }
        else{
            ans = 0; //  because we break here the consecutive chain of matching
        }
    }
    // if prev was not a match start from here
    else{
        if(similarRegion(i,j)){
            ans = max(ans, 1 + rec(i+1,j+1,true));
        }
        else{
            ans = max(ans, max(rec(i+1,j,false), rec(i,j+1,false)));
        }
    }

    return dp[i][j][match] = ans;
}

void solve()
{
    cin>>n;
    cin>>a>>b;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    int len = rec(0,0,false);
    // cout<<len<<endl;
    if(len>=(n+1)/2){
        cout<<"POSITIVE";
    }
    else{
        cout<<"NEGATIVE";
    }
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
        if(tt!=0){
            cout<<endl;
        }
    }
    return 0;
}
