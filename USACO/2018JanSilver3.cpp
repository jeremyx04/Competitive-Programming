#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 5005;
int n,q,k,ans;
vector<pair<int,int>>adj[mxN];
void dfs(int u, int p){
    for(auto &e:adj[u]){
        int v = e.first, w = e.second;
        if(v==p) continue;
        if(w>=k){
            ans++;
            dfs(v,u);
        }
    }
}
int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i = 0; i < q; i++){
        int v; cin >> k >> v;
        ans = 0;
        dfs(v,-1);
        cout << ans << '\n';
    }
}

