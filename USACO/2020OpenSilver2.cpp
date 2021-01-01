#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

int main(){
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
    int n,m; cin >> n >> m;
    vector<pair<int,int>>cow(n);
    vector<int>ans(n);
    vector<int>who(m+1);
    for(int i = 0; i < n; i++)
        cin >> cow[i].first >> cow[i].second;
    int cnt = 0;
    for(int i = n-1; i >= 0; i--){
        int cur = i, pref = cow[cur].first;
        while(true){
            if(who[pref]==0){
                who[pref] = cur;
                cnt++; 
                break;
            }
            else if(who[pref]<cur){
                break;
            }
            else{
                int tmp = who[pref];
                who[pref] = cur;
                if(cow[tmp].second == pref)
                    break;
                cur = tmp;
                pref = cow[tmp].second;
            }
        }
        ans[i] = cnt;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << '\n';
}

