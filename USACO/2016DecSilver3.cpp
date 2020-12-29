#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 205;
struct cow{
    int x,y,p;
}cows[mxN];
int n;
bool vis[mxN];
double dist(int x1, int y1, int x2, int y2){
    int dx = abs(x2-x1), dy = abs(y2-y1);
    return (sqrt(dx*dx+dy*dy));
}
void dfs(int u, int p){
    vis[u] = 1;
    for(int i = 0; i < n; i++){
        if(!vis[i]&&dist(cows[i].x,cows[i].y,cows[u].x,cows[u].y)<=cows[u].p){
            dfs(i,u);
        }
    }
}
int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cows[i].x >> cows[i].y >> cows[i].p;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int tmp = 0;
        ms(vis,0);
        dfs(i,-1);
        for(int j = 0; j < n; j++)
            if(vis[j]) tmp++;
        ans = max(ans,tmp);
    }
    cout << ans << '\n';
}

