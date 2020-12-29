#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

//idea: binary search for answer
const int mxN = 1005;
int N;
pair<int,int>cows[mxN];
bool vis[mxN];
ll dist(int x1, int y1, int x2, int y2){
    int dx = abs(x2-x1), dy = abs(y2-y1);
    return 1LL*dx*dx+dy*dy;
}
void dfs(int u, int p, ll x){
    vis[u] = 1;
    for(int i = 0; i < N; i++){
        if(!vis[i]&&dist(cows[i].first,cows[i].second,cows[u].first,cows[u].second)<=x)
            dfs(i,u,x);
    }
}
bool check(ll x){
    ms(vis,0);
    dfs(0,-1,x);
    bool ok = 1;
    for(int i = 0; i < N; i++)
        if(!vis[i]) ok = 0;
    return ok;
}
int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> cows[i].first >> cows[i].second;
    ll lb = 1, rb = 2e9;
    while(lb<=rb){
        ll mb = (lb+rb)/2; //mb = x
        if(check(mb))
            rb = mb-1;
        else
            lb = mb+1;
    }
    cout << lb << '\n';
}

