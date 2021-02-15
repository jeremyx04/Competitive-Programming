#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 1e5+5;
int g,n,par[mxN];
int find(int x){
    if(par[x]!=x)
        return par[x]=find(par[x]);
    return par[x];
}
void merge(int a, int b){
    a = find(a); b = find(b);
    par[a] = b;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> g >> n;
    iota(par,par+g+1,0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        int p = find(x);
        if(!p){
            cout << i << '\n';
            return 0;
        }
        merge(p,p-1);
    }
    cout << n << '\n';
}

