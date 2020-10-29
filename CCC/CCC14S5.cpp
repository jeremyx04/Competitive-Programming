#include<bits/stdc++.h>
using namespace std;
#define dlwlrma ios::sync_with_stdio(0); cin.tie(0);
#define pii pair<int,int>
#define f first
#define s second
struct Path{
    int x,y,d;
    bool operator < (const Path &p) const{
        return p.d>d;
    }
};
const int mxN = 2002;
const pii origin = {0,0};
int n,dp[mxN],dist1[mxN],dist2[mxN];
pii chu[mxN];
vector<Path>foxpath;
int dist(pii a, pii b){
    int x1=a.f,x2=b.f,y1=a.s,y2=b.s;
    return pow(x2-x1,2)+pow(y2-y1,2);
}
int main(){
    dlwlrma
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> chu[i].f >> chu[i].s;
    for(int i = 0; i < n; i++)
        foxpath.push_back({n,i,dist(chu[i],origin)});
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++)
            foxpath.push_back({i,j,dist(chu[i],chu[j])});
    }
    sort(foxpath.begin(),foxpath.end());
    for(auto &next : foxpath){
        if(next.d > dist1[next.x]){
            dist1[next.x] = next.d;
            dist2[next.x] = dp[next.x];
        }
        if(next.d > dist1[next.y]){
            dist1[next.y] = next.d;
            dist2[next.y] = dp[next.y];
        }
        if(next.x==n)
            dp[n] = max(dp[n],dist2[next.y]+1);
        else if (next.y==n)
            dp[n]=max(dp[n],dist2[next.x]+1);
        else{
            dp[next.x] = max(dp[next.x],dist2[next.y]+1);
            dp[next.y] = max(dp[next.y],dist2[next.x]+1);
        }
    }
    cout << dp[n] << "\n";
}