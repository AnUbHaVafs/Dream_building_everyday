#include <bits/stdc++.h>
using namespace std;
namespace Flandre_Scarlet
{
#define N 18
#define real double
#define F(i, l, r) for (int i = l; i <= r; ++i)
#define D(i, r, l) for (int i = r; i >= l; --i)
#define Fs(i, l, r, c) for (int i = l; i <= r; c)
#define Ds(i, r, l, c) for (int i = r; i >= l; c)
#define Tra(i, u) for (int i = G.Start(u), __v = G.To(i); ~i; i = G.Next(i), __v = G.To(i))
#define MEM(x, a) memset(x, a, sizeof(x))
#define FK(x) MEM(x, 0)

    int n;
    real a[N][N];
    void Input()
    {
        scanf("%d", &n);
        F(i, 0, n - 1)
        F(j, 0, n - 1) scanf("%lf", &a[i][j]);
    }

    real dp[1 << N];
    void Soviet()
    {
        int All = (1 << n) - 1;
        dp[All] = 1.00;
        D(i, All - 1, 0)
        {
            real cnt = (real)__builtin_popcount(i);
            F(j, 0, n - 1)
            if (!((1 << j) & i))
            {
                F(k, 0, n - 1)
                if ((1 << k) & i)
                {
                    real P = 1 / (cnt * (cnt + 1) / 2.00);
                    dp[i] += dp[i | (1 << j)] * a[k][j] * P;
                }
            }
        }
        F(i, 0, n - 1)
        {
            printf("%.6f ", dp[(1 << i)]);
        }
        putchar('\n');
    }

#define Flan void
    Flan IsMyWife()
    {
        Input();
        Soviet();
    }
}
int main()
{
    Flandre_Scarlet::IsMyWife();
    getchar();
    getchar();
    return 0;
}