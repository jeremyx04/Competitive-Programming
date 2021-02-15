#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 30;
int r,c,k,dp[mxN][mxN];
bool cat[mxN][mxN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c >> k;
    while(k--){
        int x,y; cin >> x >> y;
        cat[x][y] = true;
    }
    dp[1][1] = 1;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(i==1&&j==1) continue;
            if(!cat[i][j]) dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    cout << dp[r][c] << '\n';
}

