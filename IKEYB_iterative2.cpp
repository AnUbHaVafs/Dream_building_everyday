#include<bits/stdc++.h>
using namespace std;

void solve(){
    int K,L;
    cin>>K>>L;
    string keys, letters;
    cin>>keys>>letters;
    vector<int> freq(L);
    for(int i=0;i<L;i++){
        cin>>freq[i];
    }
    // dp[i][j] --> min Cost to assign first i letters to j keys and j-1 is already completely filled.
    struct dp_entry{
        int price = 0;
        int i_prev = 0; // from where we started to assign letters to jth key
    };
    vector<vector<dp_entry>> dp(L+1, vector<dp_entry>(K+1));
    for(int i=1; i<=L; i++){
        dp[i][0].price = 1e9;
        for(int j=1; j<=K; j++){
            dp[i][j] = {dp[i][j-1].price, i};
            // calcute weighted sum
            int freq_sum = 0;
            int key_cost = 0; // actual weighted sum
            for(int m=1;m<=i;m++){
                freq_sum += freq[i-m]; // 1 based i and m, will give us 0-based curr letter freq value
                key_cost += freq_sum;
                const auto p = dp[i-m][j-1].price + key_cost;
                if(p<=dp[i][j].price){ // less then AND EQUALS To since we need to min Price as well as largest number of elemnets from the last group if prices are same. VERY IMP!
                    dp[i][j] = {p, i-m};
                }
            }
        }
    }
    vector<int>letters_per_key(K);
    int i=L;
    for(int j=K;j>0;j--){
        letters_per_key[j-1] = i - dp[i][j].i_prev;
        i = dp[i][j].i_prev;
    }
    int j=0;
    for(int i=0;i<K;i++){
        cout<<keys[i]<<": ";
        while(letters_per_key[i]--){
            cout<<letters[j];
            j++;
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Keypad #" << i << ":\n";
        solve();
    }
    return 0;
}