#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 105, dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int n,k,r,cur;
vector<pair<int,int>>road[mxN][mxN];
vector<int>comp;
bool cows[mxN][mxN],vis[mxN][mxN];
void dfs(int i, int j){
    if(i<1||j<1||i>n||j>n||vis[i][j]) return;
    vis[i][j] = 1;
    if(cows[i][j]) cur++;
    for(int d = 0; d < 4; d++){
        int ni = i+dx[d], nj = j+dy[d];
        bool ok = 1;
        for(int x = 0; x < road[i][j].size(); x++){
            if(road[i][j][x].first == ni && road[i][j][x].second == nj) ok = 0;
        }
        if(ok) dfs(ni,nj);
    }
}
int main(){
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    cin >> n >> k >> r;
    for(int i = 0; i < r; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        road[a][b].push_back({c,d});
        road[c][d].push_back({a,b});
    }
    for(int i = 0; i < k; i++){
        int x,y; cin >> x >> y;
        cows[x][y] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!vis[i][j]){
                cur = 0;
                dfs(i,j);
                comp.push_back(cur);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < comp.size(); i++){
        for(int j = 0; j < i; j++){
            ans += comp[i] * comp[j];
        }
    }
    cout << ans << '\n';
}

