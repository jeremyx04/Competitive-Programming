#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define f first 
#define s second

const int INF = 0x3f3f3f3f;
struct Node{
    int mn,mx;
}st[1<<22];

void app(int i, int xl, int xr){
    st[i].mn = min(max(st[i].mn,xl),xr);
    st[i].mx = min(max(st[i].mx,xl),xr);
}
void psh(int i){
    app(i*2,st[i].mn,st[i].mx);
    app(i*2+1,st[i].mn,st[i].mx);
    st[i].mn=0;
    st[i].mx=INF;
}
void update(int l1, int r1, int xl, int xr, int i, int l2, int r2){
    if(l1<=l2&&r1>=r2){
        app(i,xl,xr);
        return;
    }
    psh(i);
    int m = (l2+r2)>>1;
    if(l1<=m)
        update(l1,r1,xl,xr,i*2,l2,m);
    if(r1>m)
        update(l1,r1,xl,xr,i*2+1,m+1,r2);
}
void build(int *finalHeight, int l1, int r1, int i){
    if(l1==r1){
        finalHeight[l1]=st[i].mn;
        return;
    }
    int m = (l1+r1)>>1;
    psh(i);
    build(finalHeight,l1,m,i*2);
    build(finalHeight,m+1,r1,i*2+1);
}
void buildWall(int n, int k, int *op, int *left, int *right, int *height, int *finalHeight){
    for(int i = 0; i < k; i++)
        update(left[i],right[i],(op[i]==1?height[i]:0),(op[i]==1?INF:height[i]),1,0,n-1);
    build(finalHeight,0,n-1,1);
}