#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 1e5+5;
int n,dp[mxN];
vector<int>adj[mxN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int u,v;
    while(cin >> u >> v && u!=0 && v!=0){
        adj[v].push_back(u);
    }
    dp[n] = 1;
    for(int i = n; i >= 1; i--){
        for(int &v:adj[i]){
            dp[v] += dp[i];
        }
    }
    cout << dp[1] << '\n';
}

