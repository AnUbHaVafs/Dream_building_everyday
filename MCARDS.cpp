#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int C,N;

int getLISOfSameColor(vector<pair<int,int>> &cards, int color){
    vector<int> lis;
    for(int i=0; i<C*N; i++){
        if(cards[i].first == color){
            if(lis.empty() || lis.back()<cards[i].second){
                lis.push_back(cards[i].second);
            }
            else{
                auto it = lower_bound(lis.begin(), lis.end(), cards[i].second);
                *it = cards[i].second;
            }
        }
    }
    return lis.size();
}

void solve()
{
    vector<pair<int,int>> cards(C*N);
    for(int i=0;i<C*N;i++){
        cin>>cards[i].first>>cards[i].second;
    }
    int ans = 0;
    for(int i=1; i<=C; i++){
        ans += getLISOfSameColor(cards, i);
    }
    cout<< (N*C) - ans <<endl;
}

int main()
{
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        while(cin>>C>>N){
            solve();
        }
    }
    return 0;
}
