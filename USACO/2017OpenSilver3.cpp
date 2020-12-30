#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 21, dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int n;
char grid[mxN][mxN];
bool vis[mxN][mxN];
vector<pair<pair<int,int>,pair<int,int>>>pcl;
bool contains(int i, int j){
    return pcl[i].first.first >= pcl[j].first.first && 
    pcl[i].first.second >= pcl[j].first.second && 
    pcl[i].second.first <= pcl[j].second.first && 
    pcl[i].second.second <= pcl[j].second.second;
}
int main(){
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
            cin >> grid[i][j];
    //Loop through all possible rectangles
    for(int x1 = 0; x1 < n; x1++){
        for(int y1 = 0; y1 < n; y1++){
            for(int x2 = x1; x2 < n; x2++){
                for(int y2 = y1; y2 <n; y2++){
                    set<char>color;
                    for(int i = x1; i <= x2; i++){
                        for(int j = y1; j <= y2; j++){
                            color.insert(grid[i][j]);
                        }
                    }
                    if((int)color.size()!=2) continue;
                    int cnt[26];
                    ms(cnt,0);
                    for(int i = x1; i <= x2; i++)
                        for(int j= y1; j <= y2; j++)
                            vis[i][j] = 0;
                    for(int i = x1; i <= x2; i++){
                        for(int j = y1; j <= y2; j++){
                            if(!vis[i][j]){
                                queue<pair<int,int>>q;
                                q.push({i,j});
                                vis[i][j]=1;
                                char cur = grid[i][j];
                                cnt[cur-'A']++;     
                                while(!q.empty()){
                                    auto c = q.front(); q.pop();
                                    for(int d = 0; d < 4; d++){
                                        int nx = c.first+dx[d], ny = c.second+dy[d];
                                        if(nx<x1||ny<y1||nx>x2||ny>y2||vis[nx][ny]||grid[nx][ny]!=cur) continue;
                                        q.push({nx,ny});
                                        vis[nx][ny] = 1;
                                    }
                                }
                            }
                        }
                    }
                    bool ok1 = 0, ok2 = 0;
                    for(int c = 0; c < 26; c++){
                        if(cnt[c]==1) ok1 = 1;
                        if(cnt[c]>=2) ok2 = 1;
                    }
                    if(ok1&&ok2)
                        pcl.push_back(make_pair(make_pair(x1,y1),make_pair(x2,y2)));
                }
            }
        }
    }
    //pcl.size should be (20C2)^2 = 36100 max i think
    //36100^2 should be fine
    int ans = 0;
    for(int i = 0; i < pcl.size(); i++){
        //cout << pcl[i].first.first << ' ' << pcl[i].first.second << ' ' << pcl[i].second.first << ' ' << pcl[i].second.second << '\n';
        //test if pcl[i] is contained by any other "pcl"
        bool ok = 1;
        for(int j = 0; j < pcl.size(); j++){
            if(i==j) continue;
            if(contains(i,j)) ok = 0;
        }
        ans+=ok;
    }
    cout << ans << '\n';
}

