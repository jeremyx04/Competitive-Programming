#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 1e5+5;
int n;
vector<int>adj[mxN];
bool vis[mxN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int x,y;
    while(cin >> x >> y && x!=0 && y!=0){
        ms(vis,0); 
        queue<pair<int,int>>q;
        q.push({x,-1});
        bool ok = 0;
        while(!q.empty()){
            auto c = q.front(); q.pop();
            if(c.first==y){
                cout << "Yes " << c.second << '\n';
                ok = 1;
                break;
            }
            for(int &v:adj[c.first]){
                if(!vis[v]){
                    q.push({v,c.second+1});
                    vis[v] = 1;
                }
            }
        }
        if(!ok){
            cout << "No\n";
            continue;
        }
    }
}