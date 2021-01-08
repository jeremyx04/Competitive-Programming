#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<ld,ld>>sheep(n);
    vector<pair<ld,ld>>ans(n);
    for(int i = 0; i < n; i++){
        cin >> sheep[i].first >> sheep[i].second;
        ans[i].first = 0.0, ans[i].second = 1000.0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==j) continue;
            auto a = sheep[i], b = sheep[j];
            if(a.first==b.first){
                if(a.second==b.second) continue;
                if(a.second<b.second) ans[j].second = -1;
                else ans[i].second = -1;
            }
            //y1 = mx1 + b, y2 = mx2 + b, y2-y1 = mx2-mx1, m (x2-x1) = y2-y1, m = (y2-y1)/(x2-x1) 
            //-1/m = (x1-x2)/(y2-y1)
            ld m = (a.first-b.first)/(b.second-a.second);
            ld x = (a.first+b.first)/2.0, y = (a.second+b.second)/2.0;
            //y = mx+b, b = y - mx 
            ld yint = y - m*x;
            //0 = mx+b, x = -b/m
            ld xint = -yint/m;
            if(a.first<b.first){
                ans[i].second = min(ans[i].second,xint);
            }
            else{
                ans[i].first = max(ans[i].first,xint);
            }
        }
    }
    cout << fixed << setprecision(2);
    for(int i = 0; i < n; i++)
        if(ans[i].first<=ans[i].second)
            cout << "The sheep at (" << sheep[i].first << ", " << sheep[i].second << ") might be eaten.\n";
}