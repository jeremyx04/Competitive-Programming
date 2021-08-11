#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 150005;
int n,m,l[mxN],r[mxN],z[mxN];
ll seg1[mxN*4],seg2[mxN*4];

ll gcd(ll a, ll b){
    return a? gcd(b%a,a) : b;
}
ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}
ll bld(int i=1, int l=1, int r=n, ll cur=1){
    cur = lcm(cur,seg1[i]);
    if(l==r) return seg2[i]=cur;
    int mb = (l+r)/2;
    return seg2[i] = gcd(bld(i*2,l,mb,cur),bld(i*2+1,mb+1,r,cur)); 
}
void upd(int l1, int r1, int v, int i=1, int l2=1, int r2=n){
    if(l1>r2||r1<l2){
        return;
    }
    if(l2>=l1&&r2<=r1){
        seg1[i] = lcm(seg1[i],v);
        if(seg1[i] > 1e9){
            cout << "Impossible\n";
            exit(0);
        }
        return;
    }
    int mb = (l2+r2)/2;
    upd(l1,r1,v,i*2,l2,mb);
    upd(l1,r1,v,i*2+1,mb+1,r2);
}
ll qry(int l1, int r1, int i=1, int l2=1, int r2=n){
    if(l1>r2||r1<l2){
        return 0;
    }
    if(l2>=l1&&r2<=r1){
        return seg2[i];
    }
    int mb = (l2+r2)/2;
    return gcd(qry(l1,r1,i*2,l2,mb),qry(l1,r1,i*2+1,mb+1,r2));
}
ll get(int x, int i=1, int l=1, int r=n){
    if(l==r)
        return seg2[i];
    int mb = (l+r)/2;
    if(x<=mb) return get(x,i*2,l,mb);
    else return get(x,i*2+1,mb+1,r);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < mxN*4; i++)
        seg1[i] = 1;
    for(int i = 1; i <= m; i++){
        cin >> l[i] >> r[i] >> z[i];
        upd(l[i],r[i],z[i]);
    }
    bld();
    for(int i = 1; i <= m; i++){
        if(qry(l[i],r[i]) != z[i]){
            cout << "Impossible\n";
            return 0;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << get(i) << ' ';
    }
    cout << '\n';
}