#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

int main(){
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    int l,n,rf,rb;
    cin >> l >> n >> rf >> rb;
    vector<pair<int,int>>grass(n);
    priority_queue<pair<int,int>>pq;
    for(int i = 0; i < n; i++){
        cin >> grass[i].second >> grass[i].first;
        pq.push({grass[i].first,grass[i].second});
    }
    ll tFJ = 0, tB = 0, lastx = 0, ans = 0;
    while(!pq.empty()){
        auto c = pq.top(); pq.pop();
        if(lastx>=c.second) continue;
        tFJ = (c.second-lastx) * rf;
        tB = (c.second-lastx) * rb;
        ans += (tFJ-tB) * c.first;
        lastx = c.second;
    }
    cout << ans << '\n';
}

