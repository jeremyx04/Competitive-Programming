#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define f first
#define s second
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));
 
const int mxN = 1005;
int N,sz,p; char a[mxN][mxN];
bool vis[mxN][mxN];
void dfs(int x, int y){    
    if(a[x][y]!='#'){
        p++; 
        return;
    }
    if(x<1||y<1||x>N||y>N) return;
    if(vis[x][y]) return;
    sz++;
    vis[x][y] = 1;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
}
int main(){
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> a[i][j];
    int area = 0, perimeter = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(!vis[i][j]){
                p = 0;
                sz = 0;
                dfs(i,j);
                if(sz>area){
                    area = sz;
                    perimeter = p;
                }
                if(sz==area){
                    perimeter = min(perimeter,p);
                }
            }
        }
    }
    cout << area << ' ' << perimeter << '\n'; 
}      
 