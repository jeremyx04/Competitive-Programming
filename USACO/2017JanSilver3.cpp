#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));


//miku -> miku umik -> mikuumik kmikuumi -> mikuumikkmikuumi imikuumikkmikuum
//
//10 -> m
//rec(9,16) -> rec(0,8) -> rec(0,4)

//??? i spent 1 hour debugging this :(
string s;
char rec(ll x, ll sz){
    if(sz==s.size()) return s[x];
    if(x<sz/2) return rec(x,sz/2);
    else if(x==sz/2) return rec(x-1,sz/2); 
    else return rec(x-sz/2-1,sz/2);
}
int main(){
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
    ll n;
    cin >> s >> n;
    ll sz = s.size();
    while(sz<n){
        sz*=2;
    }
    ll idx = n-1;
    cout << rec(idx,sz) << '\n';
}

