#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 2002;
int N,dist[mxN],dp1[mxN],dp2[mxN];
pair<int,int>miku[mxN];
struct path{
    int a,b,w;
    bool operator < (const path &p) const{
        return w<p.w;
    }
};
int get_dist(pair<int,int>x, pair<int,int>y){
    return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> miku[i].first >> miku[i].second;
    vector<path>yotsuba;
    for(int i = 0; i < N; i++){
        yotsuba.push_back({N,i,get_dist(make_pair(0,0),miku[i])});
    }
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            yotsuba.push_back({i,j,get_dist(miku[i],miku[j])});
        }
    }
    sort(all(yotsuba));
    for(auto &e:yotsuba){
        if(e.w > dist[e.a]){
            dist[e.a] = e.w;
            dp2[e.a] = dp1[e.a];
        }
        if(e.w > dist[e.b]){
            dist[e.b] = e.w;
            dp2[e.b] = dp1[e.b];
        }
        if(e.a == N) 
            dp1[N] = max(dp1[N],dp2[e.b]+1);
        else{
            dp1[e.a] = max(dp1[e.a],dp2[e.b]+1);
            dp1[e.b] = max(dp1[e.b],dp2[e.a]+1);
        }
    }
    cout << dp1[N] << '\n';
}