#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
int main(){
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int,int>>cow(n);
    for(int i = 0; i < n; i++){
        cin >> cow[i].first >> cow[i].second;
    }
    sort(all(cow),cmp);
    vector<int>minl(n),maxr(n);
    minl[0] = cow[0].second;
    for(int i = 1; i < n; i++)
        minl[i] = min(minl[i-1],cow[i].second);
    maxr[n-1] = cow[n-1].second;
    for(int i = n-2; i >= 0; i--)
        maxr[i] = max(maxr[i+1],cow[i].second);
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(minl[i]>maxr[i+1]) ans++;
    }
    cout << ans+1 << '\n';
}

