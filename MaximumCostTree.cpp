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
vector<vector<int>> graph;

int indp[100100];
int outdp[100100];

int ans[100100];
int arr[100100];

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

int getMaxDfs(int node, int par, int len){
    int ans = arr[node]*len;

    for(auto ch:graph[node]){
        if(ch!=par){
            ans += getMaxDfs(ch, node, len + 1);
        }
    }
    return ans;
}

void solve()
{
    // take graph inputs
    cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    graph = g;
    dfsin(1,0);
    dfsout(1,0,0);

    int maxFnode = -1, minFnode = n+1;
    int minValNode = n+1, maxValNode = -1;
    for(int i=1; i<=n; i++){
        ans[i] = max(indp[i], outdp[i]);
        // cout<<ans[i]<<"->";
        if(ans[i]>maxFnode){
            maxFnode = ans[i];
            minValNode = i;
        }
        else if(ans[i]==maxFnode){
            if(arr[i] < arr[minValNode]){
                minValNode = i;
            }
        }
        if(ans[i]<minFnode){
            minFnode = ans[i];
            maxValNode = i;
        }
        else if(ans[i]==minFnode){
            if(arr[i] > arr[maxValNode]){
                maxValNode = i;
            }
        }
    }
    int ans1 = getMaxDfs(minValNode, 0, 0);
    int ans2 = getMaxDfs(maxValNode, 0, 0);
    cout<<ans1<<" "<<ans2<<endl;
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