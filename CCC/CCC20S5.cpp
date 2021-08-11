#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 1e6+5;
int n,a[mxN],lst[mxN];
double ans,dp[mxN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        lst[a[i]]=i;
    }
    dp[n] = (a[1] == a[n]);
    ans = dp[n];
    for(int i = n-1; i >= 1; i--){
        if(a[1]==a[i]) dp[i] = 1;
        else if(i==lst[a[i]]) dp[i] = (ans+1)/(n-i+1);
        else dp[i] = dp[lst[a[i]]];
        ans += dp[i];
    }
    cout << fixed << setprecision(8) << ans/n << '\n';
}