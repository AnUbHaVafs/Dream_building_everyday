#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int colors[101];
pair<int,int> dp[101][101];

pair<int,int> rec(int l, int r){ // min cost to merge [l..r] with merge_value
    // pruning
    // base case
    if(l==r){
        return {0,colors[l]};
    }
    // cache check
    if(dp[l][r].first!=-1){
        return dp[l][r];
    }
    // compute and transitions
    int ans = INT_MAX;
    int merge_value = 0;

    for(int m=l; m<r; m++){
        pair<int,int> left_interval = rec(l,m);
        pair<int,int> right_interval = rec(m+1,r);
        int cost = (left_interval.second*right_interval.second) + left_interval.first + right_interval.first;
        int merge_val = (left_interval.second + right_interval.second)%100;
        if(cost<ans){
            ans = cost;
            merge_value = merge_val;
        }
    }   
    // save and return
    return dp[l][r] = {ans, merge_value};

}

void solve()
{
    memset(colors,0,sizeof(colors));
    // input
    for(int i=0;i<N;i++){
        cin>>colors[i];
    }
    // computation
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            dp[i][j] = {-1,-1};
        }
    }
    // [l,r]/interval dp implemetation
    cout<<rec(0,N-1).first<<endl;
}

int main()
{
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        while(cin>>N){
            solve();
        }
    }
    return 0;
}
