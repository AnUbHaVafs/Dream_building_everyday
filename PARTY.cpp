#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Party{
    int fees;
    int fun;
};

int budget, n;
Party parties[101];
pair<int,int> dp[101][501];

pair<int,int> rec(int level, int budget_left){
    // pruning
    // base case
    if(level==n){
        return {0,0};
    }
    if(budget_left==0){
        return {0,0};
    }
    // cache check
    if(dp[level][budget_left].first!=-1){
        return dp[level][budget_left];
    }
    // compute and transitions
    int maxFun = INT_MIN;
    int corrFees = 0;
    // attend this party[level]
    if(parties[level].fees <= budget_left){
        pair<int,int> getIntoParty = rec(level+1, budget_left-parties[level].fees);
        if(parties[level].fun + getIntoParty.second > maxFun){
            maxFun = parties[level].fun + getIntoParty.second;
            corrFees = parties[level].fees + getIntoParty.first;
        }
    }
    // don't attend this party
    pair<int, int> notAttendedParty = rec(level+1, budget_left);
    if(notAttendedParty.second > maxFun){
        maxFun = notAttendedParty.second;
        corrFees = notAttendedParty.first;
    }
    else if(notAttendedParty.second==maxFun){
        corrFees = min(corrFees, notAttendedParty.first);
    }

    return dp[level][budget_left] =  {corrFees, maxFun};
}

void solve()
{
    for(int i=0;i<n;i++){
        cin>>parties[i].fees>>parties[i].fun;
    }
    // memset(dp,-1,sizeof(dp));
    for(int i=0; i<101; i++){
        for(int j=0; j<501; j++){
            dp[i][j] = {-1,-1};
        }
    }
    pair<int, int> maxFunAndFees = rec(0,budget);
    cout<< maxFunAndFees.first << " " << maxFunAndFees.second <<endl;
}

int main()
{
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        while(cin>>budget>>n && budget!=0 && n!=0){
            solve();
        }
    }
    return 0;
}
