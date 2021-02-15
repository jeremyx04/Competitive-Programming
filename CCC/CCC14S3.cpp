#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

void solve(){  
    int n;
    cin >> n;
    stack<int>miku,yotsuba;
    for(int i = 0; i < n; i++){
        int x; cin >> x; 
        miku.push(x);
    }
    int cur = 1;
    while(true){
        bool flag = 0;
        if(!miku.empty() && miku.top() == cur){
            miku.pop(); cur++; flag = 1;
        }
        else if(!yotsuba.empty() && yotsuba.top() == cur){
            yotsuba.pop(); cur++; flag = 1;
        }
        else if(!miku.empty() && miku.top() != cur){
            yotsuba.push(miku.top()); miku.pop(); flag = 1;
        }
        if(!flag) break;
    } 
    if(cur==n+1) cout << "Y\n";
    else cout << "N\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve(); 
    }
}