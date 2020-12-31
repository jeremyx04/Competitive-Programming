#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

//Standard IO version
const int mxN = 1e6+5;
int n;
ll P[mxN],dp[mxN],sum[mxN],tot;
vector<int>adj[mxN];
void dfs(int u, int p){
    for(int &v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
        sum[u] += sum[v];
        dp[u] = max(dp[u],sum[v]);
    }
    dp[u] = max(dp[u],tot-sum[u]-P[u]);
    sum[u] += P[u];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> P[i];
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++)
        tot+=P[i];
    dfs(0,-1);
    int ans = 0; ll tmp = INF;
    for(int i = 0; i < n; i++){
        if(dp[i]<tmp){
            tmp = dp[i];
            ans = i;
        }
    }
    cout << ans << '\n';
}


