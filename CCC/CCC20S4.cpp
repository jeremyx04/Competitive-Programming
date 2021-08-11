#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 1e6+5;
string s;
int n,pre[3][mxN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    n = s.size();
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++) pre[j][i] = pre[j][i-1];
        if(s[i-1]=='A') pre[0][i]++;
        if(s[i-1]=='B') pre[1][i]++;
        if(s[i-1]=='C') pre[2][i]++;
    }
    int A = pre[0][n], B = pre[1][n], C = pre[2][n];
    int ans = INF;
    for(int i = 1; i <= n; i++){
        //i is starting point for A, try B and C after
        int a = i+A-1;
        int SAB, SAC, NA;
        if(a>=n){
            a-=n;
            SAB = pre[1][n]-pre[1][i-1]+pre[1][a];
            SAC = pre[2][n]-pre[2][i-1]+pre[2][a];
            NA = SAB+SAC;
        }
        else{
            SAB = pre[1][a]-pre[1][i-1];
            SAC = pre[2][a]-pre[2][i-1];
            NA = SAB+SAC;
        }
        int b = a+B;
        int SBA,SCA,NB,NC;
        if(b>=n){
            b-=n;
            SBA = pre[0][n]-pre[0][a]+pre[0][b];
            NB = SBA+pre[2][n]-pre[2][a]+pre[2][b];
        }
        else{
            SBA = pre[0][b]-pre[0][a];
            NB = SBA+pre[2][b]-pre[2][a];
        }
        int c = a+C;
        if(c>=n){
            c-=n;
            SCA = pre[0][n]-pre[0][a]+pre[0][c];
            NC = SCA+pre[1][n]-pre[1][a]+pre[1][c];
        }
        else{
            SCA = pre[0][c]-pre[0][a];
            NC = SCA+pre[1][c]-pre[1][a];
        }
        ans = min(ans,NA+NB-min(SAB,SBA));
        ans = min(ans,NA+NC-min(SAC,SCA));
    }
    cout << ans << '\n';
}