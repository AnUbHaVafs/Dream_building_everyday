#include <bits/stdc++.h>
using namespace std;

// Simple BigInt class to handle large integers
class BigInt
{
public:
    string value;

    BigInt(string val = "0")
    {
        value = val;
    }

    BigInt(int val)
    {
        value = to_string(val);
    }

    BigInt operator+(const BigInt &other) const
    {
        string a = value, b = other.value;
        if (a.length() < b.length())
            swap(a, b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string result = "";
        int carry = 0;
        for (size_t i = 0; i < a.length(); ++i)
        {
            int digitA = a[i] - '0';
            int digitB = (i < b.length()) ? b[i] - '0' : 0;
            int sum = digitA + digitB + carry;
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        if (carry)
            result.push_back(carry + '0');
        reverse(result.begin(), result.end());
        return BigInt(result);
    }

    friend ostream &operator<<(ostream &os, const BigInt &b)
    {
        os << b.value;
        return os;
    }
};

// Transition rules
unordered_map<int, vector<int>> nextDigits = {
    {1, {3}},
    {3, {1, 5}},
    {5, {7}},
    {7, {3, 5}}
};

int n;
unordered_map<int, unordered_map<int, BigInt>> dp;

BigInt rec(int level, int prev)
{
    if (level == n)
        return BigInt(1);
    if (dp[level].count(prev))
        return dp[level][prev];

    BigInt ans(0);
    for (int next : nextDigits[prev])
    {
        ans = ans + rec(level + 1, next);
    }
    return dp[level][prev] = ans;
}

void solve()
{
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (n == 1)
    {
        cout << 4 << endl;
        return;
    }

    dp.clear();
    BigInt total(0);
    for (int start : {1, 3, 5, 7})
    {
        total = total + rec(1, start);
    }
    cout << total << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
