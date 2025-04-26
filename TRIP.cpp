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

string s1, s2;
int dp[100][100];
int lcsLen;
char s[100];

// classical lcs
int rec(int i, int j){
    if(i==s1.size() || j==s2.size()){
        return 0;
    }

    // cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = 0;
    if(s1[i]==s2[j]){
        ans = max(ans, 1 + rec(i+1, j+1));
    }
    else{
        ans = max(rec(i+1,j), rec(i, j+1));
    }
    return dp[i][j] = ans;
}

void printAll(int na, int nb, int d){
    if(d==lcsLen){
        s[d] = 0;
        puts(s);
        return;
    }

    if(na==s1.size() || nb==s2.size()){
        return;
    }

    // sorted range for each level
    for(char ch='a'; ch<='z'; ch++){
        bool done = false;
        for(int i=na; i<s1.size(); i++){
            if(s1[i]==ch){
                for(int j=nb; j<s2.size(); j++){
                    // move to answer side
                    if(s2[j]==ch && rec(i,j)==lcsLen-d){
                        s[d] = ch;
                        printAll(i+1,j+1,d+1);
                        done = true;
                        break;
                    }
                }
            }
            if(done)break;
        }
    }
}

void solve()
{
    cin>>s1>>s2;
    SET(dp);
    lcsLen = rec(0,0);
    printAll(0,0,0);
    cout<<endl;
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