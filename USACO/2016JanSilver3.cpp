#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int n,cnt;
string s;
bool grid[4005][4005];
int main(){
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    cin >> n >> s;
    //fill fences
    int x = 2002, y = 2002;
    grid[x][y] = 1;
    for(int i = 0; i < n; i++){
        int dx = 0, dy = 0;
        if(s[i]=='N') dy = -1;
        if(s[i]=='S') dy = 1;
        if(s[i]=='W') dx = -1;
        if(s[i]=='E') dx = 1;
        x+=dx; y+=dy;
        grid[x][y] = 1;
        x+=dx; y+=dy;
        grid[x][y] = 1;
    }
    for(int i = 0; i < 4005; i++){
        for(int j = 0; j < 4005; j++){
            if(!grid[i][j]){
                cnt++;
                queue<pair<int,int>>q;
                q.push({i,j});
                grid[i][j] = 1;
                while(!q.empty()){
                    auto c = q.front(); q.pop();
                    for(int d = 0; d < 4; d++){
                        int nx = c.first+dx[d], ny = c.second+dy[d];
                        if(nx<0||ny<0||nx>4004||ny>4004) continue;
                        if(!grid[nx][ny]){
                            grid[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    cout << cnt-1 << '\n';
}

