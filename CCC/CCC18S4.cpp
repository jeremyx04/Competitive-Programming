#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int dpm = 1000000;
ll n;
ll dp[dpm];
ll rec(ll x){
    if(x<dpm&&~dp[x]) return dp[x];
    if(x==1||x==2) return dp[x]=1;
    int sq = sqrt(x);
    ll res = 0;
    for(int i = 1; i*i <= x; i++){
        if(i!=1&&(x/i)*(x/i)>x) res+=rec(x/i);
        res+=(x/i-(x/(i+1)))*rec(i);
    }
    if(x<dpm) return dp[x]=res;
    return res;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    ms(dp,-1);
    cout << rec(n) << '\n';
}