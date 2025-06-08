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
#define ALL(x) (x).begin(), (x).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
const int INF = 1e9;
const ll LLINF = 1e18;

int MOD;
struct mi {
	using ll = long long;
	ll v;
	explicit operator ll() const {
		return v;
	}
	mi() {
		v = 0;
	}
	mi(ll _v) {
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0)
			v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) {
		return a.v == b.v;
	}
	friend bool operator!=(const mi& a, const mi& b) {
		return !(a == b);
	}
	friend bool operator<(const mi& a, const mi& b) {
		return a.v < b.v;
	}
	mi& operator+=(const mi& m) {
		if ((v += m.v) >= MOD)
			v -= MOD;
		return *this;
	}
	mi& operator-=(const mi& m) {
		if ((v -= m.v) < 0)
			v += MOD;
		return *this;
	}
	mi& operator*=(const mi& m) {
		v = v * m.v % MOD;
		return *this;
	}
	mi& operator/=(const mi& m) {
		return (*this) *= inv(m);
	}

	friend mi pow(mi a, ll p) {
		mi ans = 1;
		assert(p >= 0);
		for (; p; p /= 2, a *= a)
			if (p & 1)
				ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) {
		assert(a.v != 0);
		return pow(a, MOD - 2);
	}

	mi operator-() const {
		return mi(-v);
	}
	mi& operator++() {
		return *this += 1;
	}
	mi& operator--() {
		return *this -= 1;
	}
	mi operator++(int32_t) {
		mi temp;
		temp.v = v++;
		return temp;
	}
	mi operator--(int32_t) {
		mi temp;
		temp.v = v--;
		return temp;
	}
	friend mi operator+(mi a, const mi& b) {
		return a += b;
	}
	friend mi operator-(mi a, const mi& b) {
		return a -= b;
	}
	friend mi operator*(mi a, const mi& b) {
		return a *= b;
	}
	friend mi operator/(mi a, const mi& b) {
		return a /= b;
	}
	friend ostream& operator<<(ostream& os, const mi& m) {
		os << m.v;
		return os;
	}
	friend istream& operator>>(istream& is, mi& m) {
		ll x;
		is >> x;
		m.v = x;
		return is;
	}
};

const int MAXN = 200100;
int n;
mi indp[MAXN], outdp[MAXN];
// indp[node] --> no. of ways to paint subtree of node, if node is W, then all subnodes can only be white, else if curr is B, then take prod of all (dp[c]) both W & B.
// outdp[node] --> ways to paint rest of tree which depends on 1 + (outdp[par]*product of other siblings except current vi) (maintain prefixProd and suffixProd)
// dp[node] -> no. of weys to paint if curr node is only B painted
vector<int> g[MAXN];

void dfsin(int node, int par){
    indp[node] = 1; // since product we need to compute
    for(int v:g[node]){
        if(v!=par){
            dfsin(v, node);
            indp[node] = (indp[node] * indp[v]); // combinations // ways
        }
    }
    indp[node]++; // if current node is white
}

void dfsout(int node, int par){
    // get prefix Product and suffix Product 
    mi prefixProd = 1;
    for(int v: g[node]){
        if(v!=par){
            outdp[v] = (outdp[v] * prefixProd);
            prefixProd = (prefixProd * indp[v]);
        }
    }
    // for prefix  product of suffix we need to reverse the childrens
    reverse(ALL(g[node]));
    mi suffixProd = 1;
    for(int v: g[node]){
        if(v!=par){
            outdp[v] = (outdp[v] * suffixProd);
            suffixProd = (suffixProd * indp[v]);
        }
    }
    // actual outdp[node] = 1 + outdp[par]*(itsprefixProd*itsSuffixProd)
    // (itsprefixProd*itsSuffixProd) already stored at each node's child
    for(int v:g[node]){
        if(v!=par){
            outdp[v] = (outdp[node]*outdp[v]);
            outdp[v]++;
            dfsout(v,node);
        }
    }
}

void clear(){
    for(int i=1; i<=n; i++){
        g[i].clear();
        indp[i] = 1;
        outdp[i] = 1;
    }
}

void solve()
{
    cin>>n>>MOD;
    for(int i=1; i<=n-1; i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfsin(1,0);
    for(int i=1; i<=n; i++){
        outdp[i]=1;
    }
    dfsout(1,0);
    for(int i=1; i<=n; i++){
        cout << (indp[i] - 1) * outdp[i] << endl;
    }
    clear();
}

int main()
{
    IOS
    int tt = 1;
    // cin >> tt;  
    while (tt--)
    {
        solve();
    }
    return 0;
}
