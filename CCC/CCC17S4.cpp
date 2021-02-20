#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 1e5+5;
struct edge{
    int u,v,w;
    bool old;
    bool operator < (const edge &e) const{
        if(w==e.w) return e.old<old;
        return w<e.w;
    }
};
vector<edge>miku;
int n,m,d,par[mxN];
int find(int x){
    if(par[x]!=x) return par[x]=find(par[x]);
    return par[x];
}
int merge(int x, int y){
    x = find(x); y = find(y);
    if(x==y) return 0;
    par[x] = y; 
    return 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> d;
    for(int i = 0; i < m; i++){
        int u,v,w; cin >> u >> v >> w;
        miku.push_back({u,v,w,i+1<n});
    }
    sort(all(miku));
    iota(par+1,par+1+n,1);
    int cnt = 0, ans = 0, mx = 0;
    for(auto &e:miku){
        if(merge(e.u,e.v)){
            cnt++;
            mx = max(mx,e.w);
            if(!e.old) ans++;
        }        
    }
    iota(par+1,par+1+n,1);
    for(auto &e:miku){
        if(find(e.u)!=find(e.v)){
            if(e.w < mx ||(e.w == mx && e.old))
                merge(e.u,e.v);
            else if(e.old && e.w <= d){
                cout << ans-1 << '\n';
                return 0;
            }
        }
    }
    cout << ans << '\n';
}