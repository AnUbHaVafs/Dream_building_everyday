#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
    Item(int val, int w){
        value = val;
        weight = w;
    }
};

int W,N;
vector<Item> items;
int dp[2001][2001];

int rec(int level, int w_left){
    if(level==N){
        return 0;
    }
    if(w_left==0){
        return 0;
    }
    
    if (dp[level][w_left]!=-1){
        return dp[level][w_left];
    }
    
    int ans = 0;
    //take
    if(items[level].weight <= w_left){
        ans = max(ans, rec(level+1, w_left - items[level].weight) + items[level].value);
    }
    // not_take
    ans = max(ans, rec(level+1, w_left));
    return dp[level][w_left] = ans;
}

void solve()
{
    cin>>W>>N;
    for(int i=0;i<N;i++){
        int val,w;
        cin>>w>>val;
        items.push_back(Item(val,w));
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,W)<<endl;
}

int main()
{
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
