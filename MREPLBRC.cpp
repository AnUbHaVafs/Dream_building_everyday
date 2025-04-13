#include <iostream>
#include <vector>
using namespace std;

const int MOD = 100000;

bool is_match(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

vector<char> openings = {'(', '[', '{'};
vector<char> closings = {')', ']', '}'};

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len += 2)
    {
        for (int i = 0; i + len <= n; ++i)
        {
            int j = i + len - 1;
            for (int k = i + 1; k <= j; k += 2)
            {
                int ways = 0;
                vector<char> open_opts = (s[i] == '?' ? openings : vector<char>{s[i]});
                vector<char> close_opts = (s[k] == '?' ? closings : vector<char>{s[k]});
                for (char open : open_opts)
                {
                    for (char close : close_opts)
                    {
                        if (is_match(open, close))
                        {
                            int left = (k - i == 1) ? 1 : dp[i + 1][k - 1];
                            int right = (j - k == 0) ? 1 : dp[k + 1][j];
                            ways = (ways + (1LL * left * right) % MOD) % MOD;
                        }
                    }
                }
                dp[i][j] = (dp[i][j] + ways) % MOD;
            }
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}
