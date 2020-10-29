#include<bits/stdc++.h>
using namespace std;
#define dlwlrma ios::sync_with_stdio(0);cin.tie(0);
const int mxN = 3002,mxM = 102;
int n,m,a[mxN],b[mxM],dp[mxN][mxM][mxM][2];
int solve(int i, int l, int r, int t){
    int& c = dp[i][l][r][t];
    if(c!=-1)
        return c;
    if(t){
        c = max(solve(i,l,r,0), a[i]+solve(i+1,l,r,0));
        if(l<=r)
            c = max(c,b[r]+solve(i,l,r-1,0));
    }
    else{
       c = solve(i+1,l,r,1);
       if(l<=r)
        c = max(c,solve(i,l+1,r,1)); 
    }
    if(i==n+1){
        if(l<=r){
            if(t){
                return c = b[r]+solve(i,l,r-1,0);
            }
            else{
                return c = solve(i,l+1,r,1);
            }
        }
        return c = 0;
    }
    return c;
}
int main(){
    dlwlrma
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    sort(b+1,b+m+1);
    memset(dp,-1,sizeof(dp));
    int ans = solve(1,1,m,1);
    cout << ans;
}