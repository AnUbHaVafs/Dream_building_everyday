/*
  We have a class of N students, and they are asked to form teams of any size, If a student X and Y are in the same
  team, they contribute Happy[X][Y] score to the final score of the decomposition.
  Find the best way to form the teams so that maximum happiness can be genrerated. Its given that happy[X][Y]
  == Happy[Y][X].
  N<=15
  -1e9<=Happpy[i][j]<=1e9
*/

// Form - Submask Decomposition

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define pii pair<int, int>
#define ALL(x) (x).begin(), (x).end()
#define psi pair<string, int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD = 1e9+7;
const int INF = 1e9;
const ll LLINF = 1e18;

void setIO(string s)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int MAXN = 15;

int n, happ[MAXN][MAXN];
int teamHappScore[(1<<MAXN)];

// pre-processing team happiness score, TC = O(2^n * n)
int getHappScore(int mask){
    teamHappScore[0] = 0;
    for(int mask=1; mask<(1<<MAXN); mask++){
        int temp = -1;
    for(int i=0; i<n; i++){
            if((mask&(1<<i))==1){
                temp=i; // find first set bit from 0(LSB)
                break;
            }
        }
        teamHappScore[mask]=0;
        for(int i=0; i<n; i++){
            if((mask&(1<<i))==1){
                teamHappScore[mask] += happ[i][temp]; // get Happ Score with temp as fixed with every other 1
            }
        }
        // remove the edges from this temp to other nodes and add the reduced cluster happScore to this for given mask's happ score.
        teamHappScore[mask] += teamHappScore[mask^(1<<temp)];
    }
}

// dp(mask) = best way to decompse this mask to get max happ score
// TC  = (3^n) since every poss posn in n-size bit we have 3 choices
// 1. Not in mask. (0)
// 2. In mask but not in submask (1,0)
// 3. In mask and in submask (1,1)
int rec(int mask){
    if(mask==0){
        return 0;
    }
    
    int ans = 0; // maxHapp score
    // submask iteration
    for(int submask=mask; submask; submask=(submask-1)&mask){
        int temp = teamHappScore[submask];
        ans = max(ans, temp + rec(mask^submask));
    }
    return ans;
}

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>happ[i][j];
        }
    }
    cout<<rec((1<<n)-1)<<endl;
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