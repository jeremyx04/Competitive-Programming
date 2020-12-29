#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 255;
int n,b,snow[mxN],ans=INF;
bool dp[mxN][mxN];
pair<int,int>boots[mxN];
//maximum of N*B states 
void solve(int pos, int boot){
    if(dp[pos][boot]) return;
    dp[pos][boot] = 1;
    if(pos==n-1){
        ans = min(ans,boot);
        return;
    }
    for(int npos = pos+1; npos < n && npos-pos <= boots[boot].second; npos++){
        if(boots[boot].first>=snow[npos])  
            solve(npos,boot);
    }
    for(int nboot = boot+1; nboot < b; nboot++){
        if(boots[nboot].first>=snow[pos])
            solve(pos,nboot);
    }
}
int main(){
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin >> n >> b;
    for(int i = 0; i < n; i++)
        cin >> snow[i];
    for(int i = 0; i < b; i++)
        cin >> boots[i].first >> boots[i].second; //.first = max depth of snow, .second = step size
    solve(0,0);
    cout << ans << '\n';
}

