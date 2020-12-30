#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
//send help idk what im doing 
//this is incredibly messy and took me way too longg!!!!!
const int mxN = 251, dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int n,grid[mxN][mxN],sz[mxN*mxN],cnt,cur;
pair<int,int> comp[mxN][mxN];
bool vis[mxN][mxN];
int main(){
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> grid[i][j];
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!vis[i][j]){
                cnt++;
                cur = 0;
                queue<pair<int,int>>q;
                q.push({i,j});
                vis[i][j] = 1;
                int color = grid[i][j];
                while(!q.empty()){
                    cur++;
                    auto c = q.front(); q.pop();
                    for(int d = 0; d < 4; d++){
                        int nx = c.first + dx[d], ny = c.second + dy[d];
                        if(nx<1||ny<1||nx>n+1||ny>n+1||vis[nx][ny]||grid[nx][ny]!=color)
                            continue;
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                sz[cnt] = cur;
                ans = max(ans,cur);
            }
        }
    }
    cout << ans << '\n';
    vector<pair<pair<int,int>,pair<int,int>>>miku;
    set<pair<int,int>>itsuki; //already searched pairs
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i<n&&grid[i][j]!=grid[i+1][j]) miku.push_back(make_pair(make_pair(i,j),make_pair(i+1,j)));
            if(j<n&&grid[i][j]!=grid[i][j+1]) miku.push_back(make_pair(make_pair(i,j),make_pair(i,j+1)));
        }
    }
    int ans2 = 0;
    for(auto &nakano : miku){
        int a = max(grid[nakano.first.first][nakano.first.second],grid[nakano.second.first][nakano.second.second]);
        int b = min(grid[nakano.first.first][nakano.first.second],grid[nakano.second.first][nakano.second.second]);
        auto p = make_pair(a,b);
        if(itsuki.find(p)!=itsuki.end())
            continue;
        itsuki.insert(p);
        ms(vis,0);
        queue<pair<int,int>>q;
        q.push({nakano.first.first,nakano.first.second});
        vis[nakano.first.first][nakano.first.second] = 1;
        int color1 = grid[nakano.first.first][nakano.first.second];
        int color2 = grid[nakano.second.first][nakano.second.second];
        int tmp = 0;
        while(!q.empty()){
            tmp++;
            auto c = q.front(); q.pop();
            for(int d = 0; d < 4; d++){
                int nx = c.first + dx[d], ny = c.second + dy[d];
                if(nx<1||ny<1||nx>n+1||ny>n+1||vis[nx][ny]||(grid[nx][ny]!=color1&&grid[nx][ny]!=color2))
                     continue;
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
        ans2 = max(ans2,tmp);
    }   
    cout << ans2 << '\n';
}
