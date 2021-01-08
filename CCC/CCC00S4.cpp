#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 6000; 
int n,m,dp[mxN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<int>clubs(m);
    for(int i = 0; i < m; i++)
        cin >> clubs[i];
    ms(dp,INF);
    dp[0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < m; j++){
            dp[i+clubs[j]] = min(dp[i+clubs[j]],dp[i]+1);
        }
    }
    if(dp[n]==INF){
        cout  <<  "Roberta acknowledges defeat.\n";
        return 0;
    }
    cout << "Roberta wins in "  << (dp[n]) << " strokes." << '\n';
}