    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;

    string a, b;
    int n,m;
    int dp[100005][1005];

    int rec(int i, int j){
        // cout<<i<<j<<endl;
        if(j==m){
            return 1e9;
        }
        if(i==n){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int minCharsToRemove = 1e9;
        if(a[i]==b[j]){
            minCharsToRemove = min(minCharsToRemove, rec(i+1, j+1));
            minCharsToRemove = min(minCharsToRemove, 1 + rec(i+1, j));
        }
        else{
            if(j!=0){
                minCharsToRemove = min(minCharsToRemove, rec(i,0));
            }
            else{        
                minCharsToRemove = min(minCharsToRemove, rec(i+1,0));
            }
        }
        return dp[i][j] = minCharsToRemove;
    }

    void solve()
    {
        n = a.size(), m = b.size();
        memset(dp, -1, sizeof(dp));
        if(m>n || m==0){
            cout<<0<<endl;
            return;
        }
        cout<<rec(0,0)<<endl;
    }

    int main()
    {
        int tt=1;
        // cin >> tt;
        while (tt--)
        {
            while(cin>>a>>b){
                solve();
            }
        }
        return 0;
    }
