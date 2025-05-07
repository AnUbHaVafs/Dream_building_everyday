#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
int dp[102][102][26];

signed main(){
    IOS
    int t;
    cin>>t;
    while(t--) {
        string s;
        int k,m;
        cin>>s>>k>>m;
        int n=s.size();
        int c[26][26]={0};
        while(m--){
            char c1,c2;
            int t;
            cin>>c1>>c2>>t;
            c[c1-'a'][c2-'a']=t;
        }
        for(int i=0; i<=n; ++i){
            for(int j=0; j<=k; ++j){
                for(int p=0; p<26; ++p){
                    dp[i][j][p]=-1e9;
                }
            }
        }
        for(int i=0; i<26; ++i){
            dp[0][1][i]=0;
        }
        dp[0][0][s[0]-'a']=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<=k; ++j){
                for(int p=0; p<26; ++p){
                    if(dp[i][j][p] != -1e9){
                        for(int d=0; d<26; ++d){
                            int t;
                            if(s[i+1]-'a' == d) t=0;
                            else t=1;
                            dp[i+1][j+t][d]=max(dp[i+1][j+t][d], dp[i][j][p] + c[p][d]);
                        }
                    }
                }
            }
        }
        int ans=-1e18;
        for(int i=0; i<=k; ++i){
            for(int j=0; j<26; ++j){
                ans=max(ans, dp[n-1][i][j]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
