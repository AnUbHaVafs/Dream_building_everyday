#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
int a[100000];
int dp[100000];
int Another_dp[100000];
int finalAns1;
unsigned long long int finalAns2;

void maxSubArray() {
    dp[0] = a[0];
    Another_dp[0] = 1;
    for(int i=1;i<n;i++){
        if(dp[i-1] + a[i] > a[i]){
            dp[i] = dp[i-1] + a[i];
            Another_dp[i] = Another_dp[i-1]; 
        }
        else if(a[i]> dp[i-1] + a[i]){
            dp[i] = a[i];
            Another_dp[i] = 1;
        }
        else{
            dp[i] = a[i];
            Another_dp[i] = Another_dp[i-1] + 1;
        }
    }
    finalAns1 = dp[0];
    for(int i=1;i<n;i++){
        finalAns1 = max(finalAns1, dp[i]);
    }
    finalAns2 = 0;
    for(int i=0;i<n;i++){
        if(finalAns1==dp[i]){
            finalAns2 += Another_dp[i];
        }
    }
    cout<< finalAns1 << " " << finalAns2 <<endl;
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    maxSubArray();
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
