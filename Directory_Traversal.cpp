#include <bits/stdc++.h>
using namespace std;

struct Data {
	bool is_file;  // is it a leaf
	int len;       // length of name
	int nleaves;   // number of leaves in subtree
	vector<int> children;
};

// Scenario-based In-out dp on tree problem
// FUN!

int main() {
	freopen("dirtraverse.in", "r", stdin);

	int n;
	cin >> n;

	vector<Data> bessie(n);
	int total_leaves = 0;
	for (int i = 0; i < n; i++) {
		string s;
		int m;
		cin >> s >> m;

		bessie[i].len = (int)s.size();

		if (m == 0) {
			bessie[i].is_file = 1;
			total_leaves++;
		}

		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			--x;
			bessie[i].children.push_back(x);
		}
	}

	// compute insides
	vector<long long> inside(n);
	function<void(int)> search_inside = [&](int v) {
		if (bessie[v].children.empty()) {
			bessie[v].nleaves = 1;
			return;
		}

		for (int u : bessie[v].children) {
			search_inside(u);

			// need a slash if it isn't a file
			bool slash = !bessie[u].is_file;
			bessie[v].nleaves += bessie[u].nleaves;
			inside[v] += inside[u] + ((bessie[u].len + slash) * bessie[u].nleaves);
		}
	};
	search_inside(0);

	// and then compute outsides
	vector<long long> outside(n);
	function<void(int)> search_outside = [&](int v) {
		for (int u : bessie[v].children) {
			long long same =
			    (inside[v] - inside[u]) -
			    ((bessie[u].len + !bessie[u].is_file) * (bessie[u].nleaves));

			// add all ../s too
			outside[u] = same + outside[v] + (3 * (total_leaves - bessie[u].nleaves));
			search_outside(u);
		}
	};
	search_outside(0);

	long long ans = LONG_LONG_MAX;
	for (int i = 0; i < n; i++) { ans = min(ans, outside[i] + inside[i]); }

	freopen("dirtraverse.out", "w", stdout);
	cout << ans << endl;
}