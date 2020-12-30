#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 101, dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int n,k,grid[mxN][10],sz[mxN*10],comp[mxN][10],cnt;
bool vis[mxN][10];
void dfs(int i, int j, int c){
    if(i<0||j<0||i>n||j>=10||grid[i][j]!=c||vis[i][j]) return;
    vis[i][j] = 1; comp[i][j] = cnt; sz[cnt]++;
    for(int x = 0; x < 4; x++)
        dfs(i+dx[x],j+dy[x],c);
}
int main(){
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < 10; j++)
            grid[i][j] = s[j]-'0';
    }
    while(true){
        bool done = 1;
        ms(comp,0); ms(sz,0); ms(vis,0); cnt = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 10; j++){
                if(!vis[i][j]&&grid[i][j]!=0){
                    dfs(i,j,grid[i][j]);
                    if(sz[cnt]>=k){
                        done = 0;
                    }
                    cnt++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 10; j++){
                if(sz[comp[i][j]]>=k)
                    grid[i][j] = 0;
            }
        }
        for(int i = 0; i < 10; i++){
            int top = n-1, bottom = n-1;
            while(top>=0){
                while(top>=0&&grid[top][i] == 0) top--;
                if(top>=0)
                    grid[bottom--][i] = grid[top--][i];
            }
            while(bottom>=0) grid[bottom--][i] = 0;
        }
        if(done) break;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

