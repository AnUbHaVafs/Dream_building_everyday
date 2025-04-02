#include <bits/stdc++.h>
using namespace std;

void solve(float c)
{   
    float len=2;
    float contribution = 0.0;
    int cards = 0;
    while(contribution<c){
        contribution += (1.0/(len));
        len++;
        cards++;
    }
    cout<<cards<<" card(s)"<<endl;
}

int main()
{
    float c;
    while(cin>>c && c!=0.00){
        solve(c);
    }
    return 0;
}
