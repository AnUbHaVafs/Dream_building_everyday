#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define pii pair<int, int>
#define psi pair<string, int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
const int inf = 1e9;
const ll INF = 1e18;

int n;
vector<int> graph[100100];
int M;
int dp[100100][20];

// ANCESTRAL DP

int gcd(int a, int b){
    if(a==0 || b==0) return a^b;
    return gcd(b, a%b);
}

// O(N*M*M)
int dfs(int node, int gc, int par){

    if(dp[node][gc]!=-1){
        return dp[node][gc];
    }

    int ans = 0;
    for(int x=1; x<=M; x++){
        int temp = 1; // total assignments poss for each child and get's their product, given x is assgined to current node
        int cntch = 0;
        for(auto ch:graph[node]){
            if(ch!=par){
                cntch++;
                temp *= dfs(ch, gcd(gc, x), node);
            }
        }
        if(cntch==0){
            if(gcd(gc, x) == 1){
                ans++;
            }
            else{

            }
        }
        else{
            ans += temp;
        }
    }
    return dp[node][gc] = ans;
}

void solve()
{
    dfs(1,M,0);
}

int main()
{
    IOS
    int tt;
    cin >> tt;  
    while (tt--)
    {
        solve();
    }
    return 0;
}