#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second

int n;
ll dp[10005];

class Order
{
public:
    ll st, d, price;
    Order(int st, int d, int price)
    {
        this->st = st;
        this->d = d;
        this->price = price;
    }
};

vector<Order> orders;

ll rec(int level)
{ // max. price airlines need to give [0...level] ending at level.
    if (level == 0)
    {
        return orders[0].price;
    }
    if (dp[level] != -1)
    {
        return dp[level];
    }

    ll ans = orders[level].price;
    // ll ans = 0;
    for (int i = 0; i < level; i++)
    {
        if (orders[i].st + orders[i].d  <= orders[level].st)
        {
            ans = max(ans, orders[level].price + rec(i));
        }
    }

    return dp[level] = ans;
}

bool sortByStartTime(const Order &a, const Order &b)
{
    return a.st < b.st;
}

void solve()
{
    vector<Order> newOrders;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, d, p;
        cin >> s >> d >> p;
        Order order(s, d, p);
        newOrders.push_back(order);
        // orders.push_back(order);
    }
    sort(newOrders.begin(), newOrders.end(), sortByStartTime);
    // sort(orders.begin(), orders.end(), sortByStartTime);
    orders = newOrders;
    ll ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, rec(i));
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}