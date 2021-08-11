#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 2e5+5;
int n,w,d,s[mxN],dist[mxN];
vector<int>adj[mxN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> w >> d;
    for(int i = 0; i < w; i++){
        int u,v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    queue<int>q;
    memset(dist,INF,sizeof(dist));
    q.push(n);
    dist[n] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    multiset<int>ans;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        ans.insert(i - 1 + dist[s[i]]);
    }
    for(int i = 1; i <= d; i++){
        int x,y;
        cin >> x >> y;
        ans.erase(ans.find(x-1+dist[s[x]]));
        ans.erase(ans.find(y-1+dist[s[y]]));
        swap(s[x],s[y]);
        ans.insert(x-1+dist[s[x]]);
        ans.insert(y-1+dist[s[y]]);
        cout << *ans.begin() << '\n';
    }
}