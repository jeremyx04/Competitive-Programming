#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 1e6+5;
int n,m,cnt=1;
unordered_map<int,int>mp;
vector<int>adj[mxN],radj[mxN];
bool vis[mxN];
void dfs(int u){
    vis[u] = 1;
    for(int &v : adj[u])
        if(!vis[v]) dfs(v);
}
void dfs1(int u){
    vis[u] = 1;
    for(int &v : radj[u])
        if(!vis[v]) dfs1(v);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        int u = 0, v = 0;
        if(mp[a]) u = mp[a];
        else{
            u = cnt;
            mp[a] = cnt++;
        }
        if(mp[b]) v = mp[b]; 
        else{
            v = cnt;
            mp[b] = cnt++;  
        }
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    int u,v; cin >> u >> v;
    u = mp[u]; v = mp[v];
    if(!u||!v){
        cout << "unknown\n";
        return 0;
    }
    dfs(u);
    if(vis[v]){
        cout << "yes\n";
        return 0;
    }
    ms(vis,0);
    dfs1(u);
    if(vis[v]){
        cout << "no\n";
        return 0; 
    }
    cout << "unknown\n"; 
}