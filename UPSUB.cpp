#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define pii pair<int, int>
#define psi pair<string, int>
#define f first
#define s second
const int mod = 1e9 + 7;

string s;
int n;
vector<char> lis;
int lisLen;
int dp[101];

void getLISLen(){
    for(int i=0; i<n; i++){
        if (lis.empty() || lis.back() <= s[i])
        {
            lis.push_back(s[i]);
        }
        else
        {
            auto it = upper_bound(lis.begin(), lis.end(), s[i]);
            *it = s[i];
        }
    }
    lisLen = lis.size();
}

int rec(int level){
    if(level==n-1){
        return 1;
    }

    // cache check
    if(dp[level]!=-1){
        return dp[level];
    }

    int ans = 1;
    for(int i=level+1; i<n; i++){
        if(s[i]>=s[level]){
            ans = max(ans, 1 + rec(i));
        }
    }
    return dp[level] = ans;
}

char s2[101];
vector<string> v;

void printAll(int level, int d){
    if(d==lisLen){
        s2[d]=0;
        puts(s2);
        v.push_back(s2);
        return;
    }
    if(level>=n){
        return; 
    }
    for(char ch=(d>0 ? s2[d-1] : 'a'); ch<='z'; ch++){
        bool found = false;
        for(int i=level; i<n; i++){
            if(s[i]==ch && rec(i)==lisLen-d){
                s2[d] = ch;
                printAll(i+1, d+1);
                found = true;
                break;
            }
        }
    }
}

void solve()
{
    cin>>s;
    n = s.length();
    SET(dp);
    int len = 0;
    for(int i=0 ;i<n; i++){
        len = max(len, rec(i));
    }
    lisLen = len;
    printAll(0,0);
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