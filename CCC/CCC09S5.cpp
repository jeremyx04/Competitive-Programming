#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

int n,m,k,dif[30005][1005],ans,cnt;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++){
        int x,y,r,b; cin >> x >> y >> r >> b;
        swap(x,y);
        for(int t = max(1,y-r); t <= min(n,y+r); t++){
            int l1 = max(1, x - (int) sqrt(r*r - (y-t)*(y-t))), r1 = min(m,x + (int) sqrt(r*r - (y-t)*(y-t)));
            dif[l1][t] += b; dif[r1+1][t] -= b;            
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            dif[i][j] += dif[i-1][j];
            if(dif[i][j] == ans)
                cnt++;
            if(dif[i][j] > ans){
                ans = dif[i][j];
                cnt = 1;
            }
        }
    }
    cout << ans << '\n' << cnt << '\n';
}

