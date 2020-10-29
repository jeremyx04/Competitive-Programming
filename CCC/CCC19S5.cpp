#include<bits/stdc++.h>
using namespace std;
#define dlwlrma ios::sync_with_stdio(0); cin.tie(0);
#define ll long long

const int mxN = 3002;
ll n,k,chu[mxN][mxN],tree[mxN][mxN];

void update(int x, int y, ll v){
    for(; x < mxN; x+=x&-x){
        for(int j = y; j < mxN; j+=j&-j)
            tree[x][j]=max(tree[x][j],v);
    }
}
ll query(int x, int y){
    ll mx = 0;
    for(; x > 0; x-=x&-x){
        for(int j = y; j > 0; j-=j&-j)
            mx = max(mx,tree[x][j]);
    }
    return mx;
}
int main(){
    dlwlrma
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> chu[i][j];
    ll ans = 0;
    for(int i = n; i > 0; i--){
        for(int x = i, y = 1; x <= n; x++,y++)
            update(x,n-y+1,chu[x][y]);
        for(int x = i, y = 1; x <= n; x++,y++){
            if(x+k-1<=n)
                ans+=query(x+k-1,n-y+1);
        }
    }
    cout << ans;
}