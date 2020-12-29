#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 3005;
int N,M,comp[mxN],cnt;
bool closed[mxN],vis[mxN];
vector<int>adj[mxN];
void dfs(int u, int p){
    vis[u] = 1; comp[u] = cnt;
    for(int &v: adj[u]){
        if(vis[v]||closed[v]) continue;
        dfs(v,u);
    }
}
int main(){
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < N; i++){
        bool ok = 1;
        int tmp = -1;
        for(int j = 1; j <= N; j++){
            if(!closed[j]&&tmp==-1) tmp = comp[j];
            else if(!closed[j]){
                if(comp[j]!=tmp) ok = 0;
            }
        }
        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
        int u; cin >> u;
        closed[u] = 1;
        ms(comp,-1); cnt = 0; ms(vis,0);
        for(int j = 1; j <= N; j++){
            if(!vis[j]&&!closed[j]){
                dfs(j,-1); cnt++;
            }
        }
    }
}  


