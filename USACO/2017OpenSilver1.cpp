#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

int n;
int main(){
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    cin >> n;
    vector<pair<int,int>>cow;
    for(int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        cow.push_back({y,x});
    }
    int ans = 0;
    sort(all(cow)); //.first = milk output, .second = count
    for(int l = 0, r = n-1; l < r;){
        int res = min(cow[l].second,cow[r].second);
        if(cow[l].second==cow[r].second){
            ans = max(ans,cow[l++].first+cow[r--].first);
        }
        else if(res==cow[l].second){
            cow[r].second-=res;
            ans = max(ans,cow[l++].first+cow[r].first);
        }
        else if(res==cow[r].second){
            cow[l].second-=res;
            ans = max(ans,cow[l].first+cow[r--].first);
        }
    }
    cout << ans << '\n';
}

