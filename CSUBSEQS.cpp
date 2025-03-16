// #include <bits/stdc++.h>
// using namespace std;

// string S1,S2,S3,S4;

// int rec(int i, int j, int k, int l){
//     // pruning
//     // base case
//     if(i==S1.size() || j==S2.size() || k==S3.size() || l==S4.size())return 0;
//     // cache check
//     // compute and transition
//     int ans=0;
//     // determine no. of transitions
//     set<char> s;
//     s.insert(S1[i]),s.insert(S2[j]),s.insert(S3[k]),s.insert(S4[l]);
//     int n = s.size();
//     cout<<i<<j<<k<<l<<" "<<n<<endl;
//     if(n==4){
//         // cout<<"hi 1"<<endl;
//         ans+= rec(i+1,j,k,l) + rec(i,j+1,k,l) + rec(i,j,k+1,l) + rec(i,j,k,l+1);
//     }
//     else if(n==3){
//         // cout<<"hi 2"<<endl;
//         if(S1[i]==S2[j])ans += rec(i,j,k+1,l+1) + rec(i+1,j+1,k,l+1) + rec(i+1,j+1,k+1,l);
//         if(S2[j]==S3[k])ans += rec(i+1,j,k,l+1) + rec(i,j+1,k+1,l+1) + rec(i+1,j+1,k+1,l);
//         if(S3[k]==S4[l])ans += rec(i+1,j+1,k,l) + rec(i,j+1,k+1,l+1) + rec(i+1,j,k+1,l+1);
//     }
//     else if(n==2){
//         // 3 same and 1 distinct
//         // cout<<"hi 3"<<endl;
//         if(S1[i]==S2[j] && S2[j]==S3[k])ans += rec(i,j,k,l+1) + rec(i+1,j+1,k+1,l);
//         if(S1[i]==S2[j] && S2[j]==S4[l])ans += rec(i,j,k+1,l) + rec(i+1,j+1,k,l+1);
//         if(S2[j]==S3[k] && S3[k]==S4[l])ans += rec(i+1,j,k,l) + rec(i,j+1,k+1,l+1);
//         // 2 same and 2 same
//         if(S1[i]==S2[j]) ans+= rec(i,j,k+1,l+1) + rec(i+1,j+1,k,l);
//         if(S1[i]==S3[k]) ans+= rec(i,j+1,k,l+1) + rec(i+1,j,k+1,l);
//         if(S1[i]==S4[l]) ans+= rec(i,j+1,k+1,l) + rec(i+1,j,k,l+1);
//     }
//     else if(n==1){
//         cout<<"hi 4"<<endl;
//         ans += (1 + rec(i+1,j+1,k+1,l+1));
//     }
//     // save and return
//     return ans;
// }

// void solve()
// {
//     string s1,s2,s3,s4;
//     cin>>s1;
//     cin>>s2;
//     cin>>s3;
//     cin>>s4;

//     S1=s1, S2=s2, S3=s3, S4=s4;
//     cout<<rec(0,0,0,0);
// }

// int main()
// {
//     int tt;
//     // cin >> tt;
//     tt=1;
//     while (tt--)
//     {
//         solve();
//     }
//     return 0;
// }
/*
Alfonso2 Peterssen (mukel)
SPOJ #2816 "Common Subsequences"
20 - 5 - 2009
*/
#include <cstdio>
#include <cstring>

#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long int64;

const int MAXN = 51;

int la, lb, lc, ld;
char A[MAXN], B[MAXN], C[MAXN], D[MAXN];
int64 dp[MAXN][MAXN][MAXN][MAXN];
int last[MAXN];
int pos[0x100];

int main()
{

    scanf("%s %s %s %s", A + 1, B + 1, C + 1, D + 1);
    la = strlen(A + 1) + 1;
    lb = strlen(B + 1) + 1;
    lc = strlen(C + 1) + 1;
    ld = strlen(D + 1) + 1;

    REP(i, la)
    {
        last[i] = pos[A[i]];
        pos[A[i]] = i;
    }

    REP(a, la)
    REP(b, lb)
    REP(c, lc)
    REP(d, ld)
    {
        int64 &val = dp[a][b][c][d];
        if (!a || !b || !c || !d)
            val = 1;
        else if (A[a] == B[b] && A[a] == C[c] && A[a] == D[d])
        {
            val = dp[a - 1][b][c][d] + dp[a - 1][b - 1][c - 1][d - 1];
            if (last[a])
                val -= dp[last[a] - 1][b - 1][c - 1][d - 1];
        }
        else
            val =
                (dp[a - 1][b][c][d] + dp[a][b - 1][c][d] + dp[a][b][c - 1][d] + dp[a][b][c][d - 1]) -
                (dp[a - 1][b - 1][c][d] + dp[a - 1][b][c - 1][d] + dp[a - 1][b][c][d - 1] + dp[a][b - 1][c - 1][d] + dp[a][b - 1][c][d - 1] + dp[a][b][c - 1][d - 1]) +
                (dp[a - 1][b - 1][c - 1][d] + dp[a - 1][b - 1][c][d - 1] + dp[a - 1][b][c - 1][d - 1] + dp[a][b - 1][c - 1][d - 1]) -
                (dp[a - 1][b - 1][c - 1][d - 1]);
    }

    printf("%lld\n", dp[la - 1][lb - 1][lc - 1][ld - 1] - 1 /*empty*/);

    return 0;
}