#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 1e5+5;
struct edge{
    int u,v,w,t;
    bool operator < (const edge &e) const{
        return w<e.w;
    }
};
int n,m,p,q,par[2][mxN];
vector<edge>miku;
int find(int i, int a){
    if(par[i][a]!=a) return par[i][a]=find(i,par[i][a]);
    return par[i][a];
}
int merge(int i, int a, int b){
    a = find(i,a); b = find(i,b);
    if(a==b) return 0;
    par[i][a] = b;
    return 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> p >> q;    
    ll cost=0,mincost=0;
    for(int i = 0; i < p; i++){
        int u,v,w; cin >> u >> v >> w;
        miku.push_back({u,v,w,0});
        cost+=(ll)w*n;
    }
    for(int i = 0; i < q; i++){
        int u,v,w; cin >> u >> v >> w;
        miku.push_back({u,v,w,1});
        cost+=(ll)w*m;
    }
    sort(all(miku));
    vector<int>cnt(2);
    for(int i = 1; i < mxN; i++)
        par[0][i]=par[1][i]=i;
    for(auto &e:miku){
        if(merge(e.t,e.u,e.v)){
            cnt[e.t]++;
            mincost+=(ll)e.w*((e.t?m:n)-cnt[!e.t]);
        }
    }
    cout << cost-mincost << '\n';
}

