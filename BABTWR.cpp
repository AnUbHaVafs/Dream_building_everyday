#include <bits/stdc++.h>
using namespace std;

int N;

struct Block{
    int h,w,d;

    Block() : h(0), w(0), d(0) {}

    Block(int h1,int w1, int d1){
        h = h1;
        w = w1;
        d = d1;
    }
};

bool blocksComparator(const Block &a, const Block &b){
    if(a.w!=b.w){
        return a.w<b.w;
    }
    if(a.d!=b.d){
        return a.d<b.d;
    }
    return a.h<b.h;
}

Block* getAllBlocksRotations(Block blocks[], int N, int M){
    int size = N*M;
    Block* rots = new Block[size];
    for(int i=0,j=0; (i<N && j<size); i++){
        // first rotation as it is
        Block currBlock = blocks[i];
        rots[j] = currBlock;
        j++;

        // second rotation
        rots[j] = Block(currBlock.h, currBlock.d, currBlock.w);
        j++;

        // third rotation
        rots[j] = Block(currBlock.w, currBlock.h, currBlock.d);
        j++;

        // fourth rotation
        rots[j] = Block(currBlock.w, currBlock.d, currBlock.h);
        j++;

        // fifth rotation
        rots[j] = Block(currBlock.d, currBlock.h, currBlock.w);
        j++;

        // sixth rotation
        rots[j] = Block(currBlock.d, currBlock.w, currBlock.h);
        j++;
    }
    return rots;
}


int rec(int level, Block* rots){ //max height possible of tower if it ends or if rots[level] is topmost one. 
    // pruning
    // base case
    if(level==N){
        return 0;
    }
    // cache check
    // compute and transitions
    int maxHeight=-1e8;
    for(int j=0;j<level;j++){
        // double check
        // fif we hadn't sorted the rots array then we must do this check just as in LIS
        if(rots[j].w > rots[level].w && rots[j].d > rots[level].d){
            maxHeight = max(maxHeight, rec(j, rots) + rots[level].h);
        }
    }
    // save and return
    return maxHeight;
}


void solve()
{
    while(cin>>N && N!=0){
        Block blocks[N];
        int y,x,z;
        for(int i=0;i<N;i++){
            cin>>y>>x>>z;
            blocks[i] = Block(y, x, z);
        }
        // possible rotations / dimensions of blocks 
        Block* rots = getAllBlocksRotations(blocks, N, 6);
        sort(rots, rots+N, blocksComparator);
        // main logic // LIS (order doesn;t matter and LDS)
        // form 2
        int maxHeight=-1e8;
        for(int i=0;i<N*6;i++){
            maxHeight = max(maxHeight, rec(i,rots));
        }
        cout<<maxHeight<<endl;
    }
}

int main()
{
    int tt=1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}