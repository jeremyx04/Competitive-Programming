#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 31, reactions[5][4] = {{2,1,0,2},{1,1,1,1},{0,0,2,1},{0,3,0,0},{1,0,0,1}};
bool dp[mxN][mxN][mxN][mxN]; // true = patrick win, false = roland win
void solve(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(dp[a][b][c][d]){
        cout << "Patrick\n";
    }
    else{
        cout << "Roland\n";
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < mxN; i++){
        for(int j = 0; j < mxN; j++){
            for(int k = 0; k < mxN; k++){
                for(int l = 0; l < mxN; l++){
                    for(int t = 0; t < 5; t++){
                        int ni = i - reactions[t][0], nj = j - reactions[t][1], nk = k - reactions[t][2], nl = l - reactions[t][3];
                        if(ni>=0&&nj>=0&&nk>=0&&nl>=0){
                            if(!dp[ni][nj][nk][nl]){
                                dp[i][j][k][l] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    int T;
    cin >> T;
    while(T--){
        solve(); 
    }
}

