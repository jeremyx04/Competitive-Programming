#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

void solve(){
    int n;
    cin >> n;
    int ans = n*10;
    unordered_map<string,int>mp;
    vector<string>in(n);
    for(int i = 0; i < n; i++){
        cin >> in[i];
    }
    mp[in[n-1]] = 1;
    int cnt = 1, res = 0;
    for(int i = 0; i < n; i++){
        if(!mp[in[i]]){
            mp[in[i]] = ++cnt;
            res = max(res,cnt);
        }
        else{
            cnt = mp[in[i]];
        }
    }
    cout << ans - (res-1)*20 << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve(); 
    }
}

