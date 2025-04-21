#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int o,n,N;

struct Container{
    int oxy;
    int nit;
    int weight;
    Container(int o=0, int n=0, int w=0){
        oxy = o;
        nit = n;
        weight = w;
    }
};

Container containers[1005];
int dp[1005][500][500];

// min weight of cylinders need to carry from [level..N-1] if this much oxygen and nitrogen is already taken.
int rec(int level, int oxygen, int nitrogen){
    // base case
    if(oxygen >= o && nitrogen>=n){
        return 0;
    }
    if(level==N){
        return 1e9;
    }
    // cache check
    if(dp[level][oxygen][nitrogen]!=-1){
        return dp[level][oxygen][nitrogen];
    }

    int ans = INT_MAX;
    // if oxygen is less, take oxygen
    // if(oxygen<o){
    ans = min(ans, containers[level].weight + rec(level + 1, oxygen + containers[level].oxy, nitrogen + containers[level].nit));
    // }
    // if nitrogen is less, take nitrogen
    // if(nitrogen<n){
        // ans = min(ans, containers[level].weight + rec(level + 1, oxygen, nitrogen + containers[level].nit));
    // }
    // NOT TAKE CYLINDER
    ans = min(ans, rec(level+1, oxygen, nitrogen));
    
    return dp[level][oxygen][nitrogen] = ans;
}

void solve()
{
    cin>>o>>n;
    cin>>N;
    for(int i=0; i<N; i++){
        int a,t,w;
        cin>>a>>t>>w;
        Container c(a,t,w);
        containers[i] = c;
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<endl;
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