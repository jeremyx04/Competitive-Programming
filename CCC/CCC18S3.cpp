#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 105, dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int n,m,dist[mxN][mxN];
char grid[mxN][mxN];
bool bad[mxN][mxN];
bool con(int x, int y){
    return (grid[x][y]=='U'||grid[x][y]=='L'||grid[x][y]=='R'||grid[x][y]=='D');
}
priority_queue<pair<int,pair<int,int>>>pq;
pair<int,int>start;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j]=='S') start=make_pair(i,j);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j]=='C'){
                for(int d = 0; d < 4; d++){
                    int x = i, y = j;
                    while(grid[x][y]!='W'){
                        if(!con(x,y)) bad[x][y]=1;
                        x+=dx[d]; y+=dy[d];
                    }
                }
            }
        }
    }
    if(bad[start.first][start.second]){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j]=='.') cout << -1 << '\n';
        return 0; 
    }
    ms(dist,-1);
    dist[start.first][start.second]=0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        auto c = pq.top(); pq.pop();
        auto pos = c.second;
        if(-c.first>dist[pos.first][pos.second]) continue;
        if(con(pos.first,pos.second)){
           int d = 0;
           if(grid[pos.first][pos.second]=='U') d=1;
           if(grid[pos.first][pos.second]=='R') d=2;
           if(grid[pos.first][pos.second]=='L') d=3;
           int x = pos.first+dx[d], y = pos.second+dy[d];
           if(!bad[x][y]&&grid[x][y]!='W'&&(dist[x][y]==-1||dist[x][y]>dist[pos.first][pos.second])){
               dist[x][y]=dist[pos.first][pos.second];
               pq.push(make_pair(-dist[x][y],make_pair(x,y)));
           }
        }
        else{
            for(int d = 0; d < 4; d++){
                int x = pos.first+dx[d], y = pos.second+dy[d];
                if(!bad[x][y]&&grid[x][y]!='W'&&(dist[x][y]==-1||dist[x][y]>dist[pos.first][pos.second]+1)){
                    dist[x][y]=dist[pos.first][pos.second]+1;
                    pq.push({-dist[x][y],make_pair(x,y)});
                }
            }
        }   
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j]=='.'){
                cout << dist[i][j] << '\n';
            }
        }
    }
}