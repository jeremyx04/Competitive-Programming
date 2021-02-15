#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 1e5+5;
int n,m,diameter,node;
vector<int>adj[mxN];
bool pho[mxN],miku[mxN];
void dfs(int u, int p){
    for(int &v:adj[u]){
        if(v!=p){
            dfs(v,u);
            if(miku[v]) miku[u] = 1;
        }
    }
    if(pho[u]) miku[u] = 1;
}
void dfs1(int u, int p, int d){
    if(diameter<d){
        diameter = d;
        node = u;
    }
    for(int &v:adj[u])
        if(v!=p && miku[v]) dfs1(v,u,d+1);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int tmp = -1;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        pho[x] = 1;
        tmp = x;
    }
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(tmp,-1);
    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(miku[i])
            cnt++;
    dfs1(tmp,-1,0);
    dfs1(node,-1,0);
    cout << 2*(cnt-1)-diameter << '\n';
}