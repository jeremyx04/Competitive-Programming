#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 405;
int n,miku[mxN],pre[mxN],dp[mxN][mxN];
int sum(int l, int r){
    return pre[r]-pre[l-1];
}
bool rec(int l, int r){
    if(~dp[l][r]) return dp[l][r];
    if(l>n||r>n) return 0;
    if(l>=r) return dp[l][r]=1;
    for(int tl=l,tr=r; tl<=tr; tl++){
        while(sum(tr,r)<sum(l,tl)) tr--;
        if(tl>tr) break;
        if(sum(tr,r)==sum(l,tl)){
            if(rec(l,tl)&&rec(tl+1,tr-1)&&rec(tr,r)) return dp[l][r]=1;
        }
    }
    return dp[l][r]=0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ms(dp,-1);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> miku[i];
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i-1]+miku[i];
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            if(rec(i,j)) ans = max(ans,pre[j]-pre[i-1]);
    cout << ans << '\n';
}

