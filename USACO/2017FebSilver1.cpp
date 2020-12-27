#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
int main(){
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int c,n;
    cin >> c >> n;
    vector<int>chicken(c);
    vector<pair<int,int>>cow(n);
    for(int i = 0; i < c; i++){
        cin >> chicken[i];
    }
    for(int i = 0; i < n; i++){
        cin >> cow[i].first >> cow[i].second;
    }
    sort(all(chicken));
    sort(all(cow),cmp);
    int ans = 0;
    for(int i = 0; i < n; i++){
        auto pos = lower_bound(all(chicken),cow[i].first);
        if(pos==chicken.end()) continue;    
        if(*pos<=cow[i].second){
            ans++;
            chicken.erase(pos);
        }
    }
    cout << ans << '\n';
}

