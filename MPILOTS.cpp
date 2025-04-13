#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define f first
#define s second
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
typedef long long int ll;

const int MAXN = 10001;
pii arr[MAXN];         // arr[i].f = captain salary, arr[i].s = assistant salary
ll dp[MAXN][MAXN / 2]; // dp[ind][cap] = min salary from ind with cap captains assigned
int N;                 // Total number of pilots

ll minSal(int ind, int cap)
{
    if (ind > N)
        return 0; // All pilots assigned

    if (dp[ind][cap] != -1)
        return dp[ind][cap];

    int ass = (ind - 1) - cap;

    // Case 1: Number of captains == number of assistants → assign assistant
    if (cap == ass)
        return dp[ind][cap] = arr[ind].s + minSal(ind + 1, cap);

    // Case 2: Captains left to assign == pilots left → must assign captain
    if (cap == N / 2)
        return dp[ind][cap] = arr[ind].f + minSal(ind + 1, cap + 1);

    // Case 3: Try both options
    ll assignAsst = arr[ind].s + minSal(ind + 1, cap);
    ll assignCapt = arr[ind].f + minSal(ind + 1, cap + 1);

    return dp[ind][cap] = min(assignAsst, assignCapt);
}

int main()
{
#ifndef ONLINE_JUDGE
    clock_t start_s = clock();
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> arr[i].f >> arr[i].s;

    memset(dp, -1, sizeof(dp));

    cout << minSal(1, 0) << "\n";

#ifndef ONLINE_JUDGE
    clock_t stop_s = clock();
    cout << "Time Elapsed: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) << " sec\n";
#endif

    return 0;
}
