#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 105,dx[4] = {1,-1,0,0 }, dy[4] = {0,0,1,-1};
int n,m;
vector<pair<int,int>>a[mxN][mxN];
bool on[mxN][mxN],vis[mxN][mxN];
void dfs(pair<int,int>u){
    if(u.first<1||u.second<1||u.first>n||u.second>n||vis[u.first][u.second]||!on[u.first][u.second]) return;
    vis[u.first][u.second] = 1;
    for(auto x : a[u.first][u.second]){
        on[x.first][x.second] = 1;
        for(int i = 0; i < 4; i++)
            if(vis[x.first+dx[i]][x.second+dy[i]]) dfs({x.first,x.second});
    }
    for(int i = 0; i < 4; i++){
        dfs({u.first+dx[i],u.second+dy[i]});
    }

}
int main(){
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x,y,xx,yy;
        cin >> x >> y >> xx >> yy;
        a[x][y].push_back({xx,yy});
    }
    on[1][1] = 1;
    dfs({1,1});
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(on[i][j]) ans++;
    cout << ans << '\n';
}

