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

int indp[100100];
int outdp[100100];

int ans[100100];

void dfsin(int node, int par){
    indp[node] = 0;

    for(auto ch:graph[node]){
        if(ch!=par){
            dfsin(ch, node);
            indp[node] = max(indp[node], indp[ch] + 1);
        }
    }
}

void dfsout(int node, int par, int outVal){
    outdp[node] = outVal;

    int max1 = -1, max2 = -1;
    for(auto ch:graph[node]){
        if(ch!=par){
            if(indp[ch]>max1){
                max2 = max1;
                max1 = indp[ch];
            }
            else if(indp[ch]>max2){
                max2 = indp[ch];
            }
        }
    }

    for(auto ch:graph[node]){
        if(ch!=par){
            if(indp[ch]==max1){
                dfsout(ch, node, max(outdp[node]+1, max2+2));
            }
            else{
                dfsout(ch, node, max(outdp[node]+1, max1+2));
            }
        }
    }
}

void solve()
{
    // take graph inputs
    dfsin(1,0);
    dfsout(1,0,0);

    for(int i=1; i<=n; i++){
        ans[i] = max(indp[i], outdp[i]);
        cout<<ans[i]<<" ";
    }
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