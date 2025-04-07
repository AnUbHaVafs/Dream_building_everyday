#include <bits/stdc++.h>
using namespace std;

int dp[31][100];

string getLast2Chars(int currChar, string last2Chars){
    if(last2Chars.size()==0){
        last2Chars = "";
        last2Chars += to_string(currChar);
    }
    else if(last2Chars.size()==1){
        last2Chars += to_string(currChar);
        reverse(last2Chars.begin(), last2Chars.end());   
    }
    else if(last2Chars.size()==2){
        last2Chars[1] = last2Chars[0];
        last2Chars[0] = '0' + currChar;
    }
    return last2Chars;
}

int rec(int level, string s){
    //pruning
    // base case
    if(level==0){
        return 1;
    }
    //cache check
    if(dp[level][s.size() ? stoi(s): 0] != -1){
        return dp[level][s.size() ? stoi(s) : 0];
    }
    // compute and transitions
    int ans=0;
    // if less than 2 char taken then any letter can come at level
    if(s.size()<2){
        string prev2chars;
        // X // Y // Z
        for(int i=1;i<=3;i++){
            ans += rec(level - 1, getLast2Chars(i, s));
        }
    }
    // else find the one which does not make the string special
    else{
        // place Z
        if(s!="12" && s!="21"){
            ans += rec(level-1, getLast2Chars(3,s));
        }
        // place X
        if(s!="32" && s!="23"){
            ans += rec(level-1, getLast2Chars(1,s));
        }
        // place Y
        if(s!="13" && s!="31"){
            ans += rec(level-1, getLast2Chars(2,s));
        }
    }
    return dp[level][s.size() ? stoi(s): 0] = ans;
}

void solve()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(n, "");
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
