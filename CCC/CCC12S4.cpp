#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

int n;
string s,ans;
unordered_map<string,int>dist;
unordered_map<string,bool>vis;
queue<string>q;
int get_pos(string x, int a){
    a*=(n+1);
    while(x[a]!=' ') a++;
    return a;
}
void go(string x, int a, int b){
    if(b<0||b>=n) return;
    int posa = get_pos(x,a),posb = get_pos(x,b);
    string tmp = x;
    if(a*(n+1)==posa) return;
    if(b*(n+1)==posb){
        tmp[posb] = tmp[posa-1];
        tmp[posa-1] = ' ';
    }
    else if(x[posa-1] < x[posb-1]){
        tmp[posb] = x[posa-1];
        tmp[posa-1] = ' ';
    }
    else return;
    if(!vis[tmp]){
        q.push(tmp);
        vis[tmp] = 1;
        dist[tmp] = dist[x] + 1;
    }
}
void solve(){
    dist.clear(); vis.clear(); 
    while(!q.empty()) q.pop();
    s = ""; ans = "";
    for(int i = 0; i < n*(n+1); i++){
        s = s + ' '; 
        ans = ans + ' ';
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        s[i*(n+1)] = x + '0';
        ans[i*(n+1)] = i + '1';
    }
    q.push(s);
    vis[s] = 1; dist[s] = 0;
    while(!q.empty()){
        string c = q.front(); q.pop();
        for(int i = 0; i < n; i++){
            go(c,i,i-1); go(c,i,i+1);
        }
        if(vis[ans]) break;
    }
    if(dist.find(ans)==dist.end()){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << dist[ans] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin >> n && n != 0){
        solve();
    }
}