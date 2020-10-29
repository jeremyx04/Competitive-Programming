#include<bits/stdc++.h>
using namespace std;
#define dlwlrma ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
struct Edge{
    int s,d,w,t;
    bool operator < (const Edge &e) const{
        if(e.w==w)
            return t<e.t;
        return w<e.w;
    }
};
const int mxN=1e5+2;
int n,m,p,q;
vector<vector<int>> par(2,vector<int>(mxN)),rnk(2,vector<int>(mxN));
vector<Edge>chu;
int find(int a, int b){
    if(par[a][b]!= b)
        par[a][b]=find(a,par[a][b]);
    return par[a][b];
}
int merge(int t, int a, int b){ 
    int x = find(t,a);
    int y = find(t,b);
    if(x==y)
        return 0;
    if(rnk[t][x]>rnk[t][y])
        par[t][y]=x;
    else
        par[t][x]=y;
    if(rnk[t][x]==rnk[t][y])
        rnk[t][y]++;
    return 1;   
}
int main(){
    dlwlrma
    cin >> n >> m >> p >> q;
    int a,b,c;
    ll cost=0,mincost=0;
    for(int i = 0; i < p; i++){
        cin >> a >> b >> c;
        chu.push_back({a,b,c,0});
        cost+=c*(ll)n;
    }
    for(int i = 0; i < q; i++){
        cin >> a >> b >> c;
        chu.push_back({a,b,c,1});
        cost+=c*(ll)m;
    }
    iota(par[0].begin(),par[0].end(),0);
    iota(par[1].begin(),par[1].end(),0);
    sort(chu.begin(),chu.end());
    vector<int>cnt(2);
    for(Edge e: chu){
        if(merge(e.t,e.s,e.d)){
            cnt[e.t]++;
            mincost+=((e.t ? m : n) - cnt[!e.t])*(ll)e.w;
        }
    }
    cout << cost-mincost;
}