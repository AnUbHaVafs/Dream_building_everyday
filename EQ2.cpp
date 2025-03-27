#include <bits/stdc++.h>
using namespace std;

string a,b,c;
int n,m,k;
int dp[10][10];

void padWithZeros(std::string &s, size_t targetSize) {
    if (s.size() < targetSize) {
        s.insert(0, targetSize - s.size(), '0');  // Prepend zeros
    }
}

vector<string> splitEq(string s){
    vector<string> arr;
    string s1="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='+' || s[i]=='='){
            arr.push_back(s1);
            s1="";
        }
        else{
            string s2(1,s[i]);
            s1+=s2;
        }
    }
    arr.push_back(s1);
    return arr;
}

int rec(int level, int carry) {
    if (level == 0) {
        return carry == 0;  // If carry is zero at the last step, it's a valid case.
    }
    if(dp[level][carry]!=-1)return dp[level][carry];
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        if (a[level - 1] != '?' && a[level - 1] - '0' != i) continue;  // Fixed index
        for (int j = 0; j <= 9; j++) {
            if (b[level - 1] != '?' && b[level - 1] - '0' != j) continue;  // Fixed index

            int sum = i + j + carry;
            int d3 = (c[level - 1] == '?' ? sum % 10 : c[level - 1] - '0'); // Fix for `?`
            
            if (d3 == sum % 10) {  // Ensure correct digit is placed
                ans += rec(level - 1, sum / 10);  // Pass correct carry
            }
        }
    }
    return dp[level][carry] = ans;
}

 
void solve()
{
    string s;
    int cnt=1;
    while (cin >> s){
        vector<string> vars = splitEq(s);
        a=vars[0],b=vars[1],c=vars[2];
        n=a.size(),m=b.size(),k=c.size();
        padWithZeros(a,k);
        padWithZeros(b,k);
        padWithZeros(c,k);
        memset(dp, -1, sizeof(dp));
        cout<<"Case "<<cnt<<": "<<rec(k,0)<<endl;
    }


}

int main()
{
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
