#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 105;
bool dp[mxN][mxN][mxN];
int mxx,mxy,k,m,ans=INF;
//recursion to find all possible states then find best answer.
void rec(int x, int y, int moves){
    if(dp[x][y][moves]||moves>k) return;
    rec(mxx,y,moves+1);
    rec(x,mxy,moves+1);
    rec(0,y,moves+1);
    rec(x,0,moves+1);
    rec((x+y<=mxy?0:x+y-mxy),min(mxy,x+y),moves+1);
    rec(min(mxx,x+y),(x+y<=mxx?0:x+y-mxx),moves+1);
    ans = min(ans,abs(m-(x+y)));
    dp[x][y][moves] = 1;
}
int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    cin >> mxx >> mxy >> k >> m;
    rec(0,0,0);
    cout << ans << '\n';
}

