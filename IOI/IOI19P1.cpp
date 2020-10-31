#include<bits/stdc++.h>
using namespace std;

const int mxN = 2e5+2;
long long tree[mxN];
int n;
vector<int>pos[mxN],neg[mxN];
void update(int x, int v){
    for(; x <= n*2; x+=x&-x)
        tree[x]+=v;
}
long long query(int x){
    long long res = 0;
    for(; x > 0; x-=x&-x)
        res+=tree[x];
    return res;
}
long long count_swaps(vector<int> S){
    n = S.size()/2;
    long long ans = 0;
    vector<int>chu(n*2);
    for(int i = 0; i < n*2; i++){
        if(S[i]<0)
            neg[abs(S[i])].push_back(i);
        else
            pos[S[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < pos[i].size(); j++){
            if(pos[i][j]<neg[i][j]){
                chu[pos[i][j]]=chu[neg[i][j]]=pos[i][j];
                ans++;
            }
            else{
                chu[pos[i][j]]=chu[neg[i][j]]=neg[i][j];
            }
        }
    }
    for(int i = n*2-1; i >= 0; i--){
        ans+=query(chu[i]);
        update(chu[i]+1,1);
    }
    return ans;
}