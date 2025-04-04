#include <bits/stdc++.h>
using namespace std;

int K,L;
char keys[90];
char letters[90];
unordered_map<char,int> freq;
int dp[91][91];

vector<string> ansCheck = {"ABCD", "EFG", "HIJK", "LM", "NOPQ", "RS", "TUV", "WXYZ"};

int getTrueAns(){
    int ans=0;
    int n = ansCheck.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<ansCheck[i].size();j++){
            ans += (j+1)*freq[ansCheck[i][j]];
        }
    }
    return ans;
}

int l=0;
int rec(int r, int k){
    // cout<<l<<r<<k<<endl;
    // cout<<"l"<<endl;
    // pruning
    if(l>r){
        return 0;
    }
    // base cases
    if(l==r){
        if(k>0)return (1*freq[letters[r]]);
        else return 1e9;
    }
    if(k==0){
        return 1e9;
    }
    // cache check
    if(dp[r][k]!=-1){
        return dp[r][k];
    }
    // compute and transitions
    int minPrice = 1e9;
    for(int cnt=1;cnt<=(r-l+1);cnt++){
        int keyPrice = 0;
        for(int i=1;i<=cnt;i++){
            keyPrice += (i*freq[letters[r-cnt+i]]);
        }
        minPrice = min(minPrice, rec(r-cnt,k-1) + keyPrice);
    }
    // save and return
    return dp[r][k] = minPrice;

}

void solve()
{
    //input
    cin>>K>>L;
    for(int i=0;i<K;i++)cin>>keys[i];
    for(int i=0;i<L;i++)cin>>letters[i];
    for(int i=0;i<L;i++){
        int fr;
        cin>>fr;
        freq[letters[i]] = fr;
    }
    //output
    // cout<<k<<" "<<l;
    // cout<<endl;
    // for(int i=0;i<k;i++)cout<<keys[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<l;i++)cout<<letters[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<l;i++){
    //     cout<<letters[i]<<"--> "<<freq[letters[i]]<<endl;
    // }
    // cout<<endl;


    // recursion
    memset(dp,-1,sizeof(dp));
    int ans = rec(L-1,K);
    cout<<ans<<endl;
    // cout<<getTrueAns();
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
