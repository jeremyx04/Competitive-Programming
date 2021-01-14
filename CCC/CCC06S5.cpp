#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int dx[8] = {0,0,1,1,1,-1,-1,-1}, dy[8] = {1,-1,0,1,-1,0,1,-1};
int n,m,a,b,c;
vector<int>adj[1<<20];
bool vis[1<<20];
int get(int i, int j){
    return i*m + j;
}
int nxt(int cur){
    int ret = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int cnt = 0;
            for(int d = 0; d < 8; d++){
                int nx = i+dx[d], ny = j+dy[d];
                if(nx<0||ny<0||nx>=n||ny>=m) continue;
                int tmp = get(nx,ny);
                if(cur>>tmp&1) cnt++;
            }
            if(cur>>get(i,j)&1){
                if(cnt>=a&&cnt<=b) ret |= 1 << get(i,j);
            }
            else{   
                if(cnt>c) ret |= 1 << get(i,j);
            }    
        }
    }  
    return ret; 
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> a >> b >> c; 
    for(int i = 0; i < (1 << (n*m)); i++){
        adj[nxt(i)].push_back(i);
    }
    int mask = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char ch; cin >> ch;
            if(ch=='*') mask |= 1 << get(i,j);
        }
    }
    queue<pair<int,int>>q;
    q.push({mask,0});
    vis[mask] = 1;
    while(!q.empty()){
        auto c = q.front(); q.pop();
        if(adj[c.first].empty()){
            cout << c.second << '\n';
            return 0;
        }
        for(int &v: adj[c.first]){
            if(!vis[v]){
                vis[v] = 1;
                q.push({v,c.second+1});
            }
        }
    }
    cout << -1 << '\n';
}