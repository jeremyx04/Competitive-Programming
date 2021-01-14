#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

int xr,yr,xj,yj,n,m,b;
bool between(int a, int x, int y){
    return (a>=x&&a<=y) || (a>=y&&a<=x);
}
bool good(int x1, int y1, int x2, int y2){
    //find line between (x1,y1) and (x2,y2), find intersection of that line and line between two people
    //if intersection point lies between x1 to x2 and y1 to y2, then return true
    int m1, b1;
    if(x1==x2){
        m1 = 1e9;  b1 = -1;
    }
    else{
        m1 = (y2-y1)/(x2-x1), b1 = y1 - m * x1;
    }
    if(m==m1){
        if(m!=1e9){
            return b == b1 && (between(xr,x1,x2) || between(xj,x1,x2));
        }
        else{
            return between(y1,yr,yj) || between(y2,yr,yj);
        }
    }
    else{
        //y = m1x + b1, y = m2x + b2
        //m1x + b1 = m2x + b2, m1x - m2x = b2-b1, x(m1-m2) = b2-b1
        int ix,iy;
        if(m!=1e9&&m1!=1e9){
            ix = (b1-b)/(m-m1);
            iy = m*ix + b;
        }
        if(m==1e9){
            ix = xr; iy = m1 * ix + b1;
        }
        if(m1==1e9){
            ix = x1; iy = m * ix + b;
        }
        return (between(ix,x1,x2)&&between(iy,y1,y2)&&between(ix,xr,xj)&&between(iy,yr,yj));
    }
    
}
int go(){
    int v; cin >> v;
    vector<int>x(v),y(v);
    for(int i = 0; i < v; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i < v; i++)
        if(good(x[i-1],y[i-1],x[i],y[i])) return 1;
    if(good(x[v-1],y[v-1],x[0],y[0])) return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> xr >> yr >> xj >> yj >> n;
    //y1 = mx1 + b, y2 = mx2 + b, m = (y2-y1)/(x2-x1)
    if(xr==xj){
        m = 1e9; b = -1;
    }
    else{
        m = (yj-yr) / (xj-xr);
        b = yj - m * xj;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += go();
    }
    cout << ans << '\n';
}