#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int m;

// int LIS(vector<pair<int,int>> &dolls){
//     int dp[m];
//     memset(dp,0,sizeof(dp));
//     dp[0]=1;
//     for(int i=m-1; i>=0; i--){
//         for(int j=0; j<i; j++){
//             if(dolls[j].first<dolls[i].first && dolls[j].second < dolls[i].second){
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//     }
//     int len = 0;
//     for(int i=0; i<m; i++){
//         len = max(len, dp[i]);
//     }
//     return len;
// }

bool custCmp(pair<int,int> a, pair<int, int> b){
    if(a.first == b.first) return a.second<b.second;
    return a.first<b.first;
}

void solve()
{
    cin>>m;
    vector<pair<int,int>>dolls(m);
    for(int i=0; i<m; i++){
        cin>>dolls[i].first>>dolls[i].second;
    }

    sort(dolls.begin(), dolls.end(), custCmp);
    // for(auto p:dolls){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
    int cnt=1;
    for(int i=1; i<m; i++){
        if(dolls[i].first <= dolls[i-1].first || dolls[i].second<=dolls[i-1].second){
            cnt++;
        }
    }
    cout<<cnt<<endl;

    int ans = 0;
    // int len = LIS(dolls);
    // int ans = m - (len==1 ? 0 : len);
    // cout<<ans<<endl;
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
