#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 1e5+5;
int n, s[mxN],par[mxN];
int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        par[s[i]]++;
    }
    queue<int>q;
    int ans = n;
    for(int i = 1; i <= n; i++){
        if(!par[i]){ q.push(i); ans--;};
    }
    while(!q.empty()){
        int c = q.front(); q.pop();
        if(!--par[s[c]]){
            q.push(s[c]);
            ans--;
        }
    }
    cout << ans << '\n';
}

