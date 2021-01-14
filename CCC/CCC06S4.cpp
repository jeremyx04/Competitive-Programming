#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n && n!=0){
        vector<vector<int>>grid(n+1,vector<int>(n+1));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cin >> grid[i][j];
        bool bad = 0;
        for(int x = 1; x <= n; x++){
            for(int y = 1; y <= n; y++){
                for(int z = 1; z <= n; z++){
                    if(grid[x][grid[y][z]] == grid[grid[x][y]][z]) continue;
                    else bad = 1;
                }
            }
        }
        if(bad){
            cout << "no\n";
            continue;
        }
        int identity = -1; 
        bool inverse = 0;
        for(int i = 1; i <= n; i++){
            bool ok = 1;
            for(int j = 1; j <= n; j++){
                if(grid[i][j]!=j) ok = 0;
            }
            for(int j = 1; j <= n; j++){
                if(grid[j][i]!=j) ok = 0;
            }

            if(ok){
                identity = i;
                bool inv = 1;
                for(int x = 1; x <= n; x++){
                    bool ok1 = 0;
                    for(int y = 1; y <= n; y++){
                        if(grid[x][y]==identity&&grid[y][x]==identity) ok1 = 1;
                    }
                    if(!ok1) inv = 0;
                }
                inverse |= inv;
            }
        }
        if(identity==-1){
            cout << "no\n";
            continue;
        }
        if(!inverse){
            cout << "no\n";
            continue;
        }
        cout << "yes\n";
    }    
}
