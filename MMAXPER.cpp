#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Rect{
    int a,b;
};

int N;
vector<Rect> rect(1005);
int dp[1005][10001];

int rec(int level, int prev_h){
    // pruning
    // base case
    if(level==0){
        return 0;
    }
    // cache check
    if(dp[level][prev_h]!=-1){
        return dp[level][prev_h];
    }
    //compute and transitions
    int ans = INT_MIN;
    int a = rect[level].a, b = rect[level].b;
    // take a as width and b as height
    ans = max(ans, a + (level==N ? 0 : abs(b-prev_h)) + rec(level-1, b));
    // take b as width and a as height
    ans = max(ans, b + (level==N ? 0 : abs(a-prev_h)) + rec(level-1, a));
    // save and return
    return dp[level][prev_h] = ans;
}

void solve()
{
    // input
    for(int i=1; i<=N; i++){
        cin>>rect[i].a>>rect[i].b;
    }
    rect[0].a = 0, rect[0].b = 0;
    memset(dp,-1,sizeof(dp));
    cout<<rec(N,0)<<endl;
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
