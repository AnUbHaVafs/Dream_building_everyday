#include <bits/stdc++.h>
using namespace std;

const int MAXP = 10000;
// knowing that 500th prime no.  which can be represented as a sum of two squares will fall under 8000th normal prime number
bool squares[MAXP];
int square_primes[MAXP];
bool mark[MAXP];
int p=0;

void sieve(){
    memset(mark,true,sizeof(mark));
    memset(squares, false, sizeof(squares));
    for(int i=0; i*i<MAXP; i++){
        squares[i*i]=true;
    }    
    // sieve of eratosthenes
    for(int i=2; i<MAXP; i++){
        if(mark[i]){
            for(int j=0;j*j<i;j++){
                if(squares[i-j*j]){
                    // we found a prime which is a sum of two squares
                    square_primes[p++]=i;
                    // cout<<j<<" "<<sqrt(squares[i-j*j])<<endl;
                    break;
                }
            }
            for(int j=i*i; j<MAXP; j+=i){
                mark[j]=false;
            }
        }
    }
}

int dp[MAXP+1][4];

int rec(int sum_left, int k){
    //pruning
    // base case
    if(sum_left==0)return 1;
    if(k==1) return 1;
    if(k<=0)return 0;
    // cache check
    if(dp[sum_left][k]!=-1) return dp[sum_left][k];
    // compute and transiiotn
    int ans=0;
    ans = rec(sum_left,k-1);
    if(sum_left>=k){
        ans += rec(sum_left-k, k);
    }
    // save and return
    return dp[sum_left][k] = ans;
}

void solve()
{
    sieve();
    int n,k;
    cin>>n>>k;
    // for(int i=0; i<MAXP; i++)cout<<square_primes[i]<<endl;
    cout<<rec(square_primes[n-1],k);
}

int main()
{
    int tt;
    cin >> tt;
    memset(dp,-1,sizeof(dp));
    while (tt--)
    {
        solve();
        if(tt!=0)cout<<endl;
    }
    return 0;
}
