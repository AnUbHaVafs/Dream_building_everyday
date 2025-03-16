    #include <bits/stdc++.h>
    using namespace std;

    long long ** ANK;
    long long MOD = 1000000003;

    int linPerm(int N, int K){
        // pruning
        // base case
        if(N==0)return 0;
        if(K==0) return 1;
        if(N==1 && K==1){
            ANK[N][K]=1;
            return 1;
        }
        if(K>(N+1)/2){
            ANK[N][K]=0;
            return 0;
        }
        if(K==1){
            ANK[N][K]=1;
            return N;
        }
        // cache check
        if(ANK[N][K]!=-1)return ANK[N][K];
        // compute and tranition
        long long ans;
        ans = (linPerm(N-2,K-1) + linPerm(N-1,K))%MOD;
        // save and return
        return ANK[N][K] = ans;
    }

    void solve()
    {
        int N,K;
        cin>>N>>K;
        ANK = new long long *[N+1];
        for(int i=0;i<N+1;i++){
            ANK[i] = new long long [K+1];
            for(int j=0;j<K+1;j++){
                ANK[i][j]=-1;
            }
        }
        long long ans = (linPerm(N-3,K-1) + linPerm(N-1,K))%MOD;
        cout<<ans;
    }

    int main()
    {
        int tt;
        tt=1;
        // cin >> tt;
        while (tt--)
        {
            solve();
            if(tt!=0)cout<<endl;
        }
        return 0;
    }
