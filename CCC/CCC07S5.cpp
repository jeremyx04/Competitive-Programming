#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

void solve(){
    int n,k,w;
    cin >> n >> k >> w;
    vector<int>pre(n+1);
    for(int i = 1; i <= n; i++){
        cin >> pre[i];
        pre[i] += pre[i-1];
    }
    vector<vector<int>>dp(k+1,vector<int>(n+1));
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = max(dp[i][j-1],dp[i-1][max(0,j-w)]+pre[j]-pre[max(0,j-w)]);
        }
    }
    cout << dp[k][n] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve(); 
    }