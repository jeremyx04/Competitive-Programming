#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 1e6+5;
ll n,p[mxN],w[mxN],d[mxN],max_p;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<pair<ll,ll>>miku;
    for(int i = 0; i < n; i++){ 
        cin >> p[i] >> w[i] >> d[i]; 
        max_p = max(max_p,p[i]);
        miku.push_back({max(0LL,p[i]-d[i]),-w[i]});
        miku.push_back({p[i]+d[i],-w[i]});
    }   
    sort(miku.begin(),miku.end());
    ll cur = 0;
    for(int i = 0; i < n; i++){
        ll tmp1 = 0,tmp2=d[i];
        if(p[i]>=tmp1&&p[i]<=tmp2) continue;
        cur += min(abs(p[i]-tmp1),abs(p[i]-tmp2))*w[i];
    }
    ll cur_slope = 0;
    for(int i = 0; i < n; i++){
        cur_slope += w[i];
    }
    ll ans = cur;
    ll prev = 0;
    for(auto &x : miku){
        ll d = x.first-prev;
        cur -= cur_slope*d;
        cur_slope += x.second;
        ans = min(ans,cur);
        prev = x.first;
    }
    cout << ans << '\n';
    
}