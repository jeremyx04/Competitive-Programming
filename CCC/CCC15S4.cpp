#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

struct edge{
    int v,t,h;
    bool operator < (const edge &e) const{
        return t>e.t;
    }
};
const int mxN = 2005;
int k,n,m,a,b,dist[mxN][205];
vector<edge>adj[mxN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> k >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v,t,h;
        cin >> u >> v >> t >> h;
        adj[u].push_back({v,t,h});
        adj[v].push_back({u,t,h});
    }
    ms(dist,INF);
    cin >> a >> b;
    priority_queue<edge>pq;
    dist[a][k] = 0;
    pq.push({a,0,k});
    while(!pq.empty()){
        auto c = pq.top(); pq.pop();
        int u = c.v;
        for(auto &v:adj[u]){
            if(c.h>v.h && dist[v.v][c.h-v.h]>dist[u][c.h]+v.t){
                dist[v.v][c.h-v.h] = dist[u][c.h]+v.t;
                pq.push({v.v,dist[v.v][c.h-v.h],c.h-v.h});
            }
        }
    }
    int ans = INF;
    for(int i = 1; i <= k; i++){
        ans = min(ans,dist[b][i]);
    }
    cout << (ans == INF ? -1 : ans) << '\n';
}
