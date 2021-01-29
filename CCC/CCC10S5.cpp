#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 1000; 
string s;
char ch;
int x,tree[mxN],idx=0,dp[mxN][2505],leftdp[mxN][2505],rightdp[mxN][2505];
void bld(int u){
    ch = s[idx++];
    while(ch == ' ') ch = s[idx++];
    if(ch == '('){
        bld(u*2);
        bld(u*2+1);
        ch = s[idx++];
        while(ch == ' ') ch = s[idx++];
    }
    else if(ch>='0'&&ch<='9'){
        int miku = ch-'0';
        ch = s[idx++];
        while(ch>='0'&&ch<='9'){
            miku*=10; miku+=ch-'0';
            ch = s[idx++];
        }
        idx--;
        tree[u] = miku;
    }
}
void dfs(int u){
    if(tree[u]){
        //leaf node
        for(int i = 0; i <= x; i++)
            dp[u][i] = tree[u] + i;
    }
    else{
        dfs(u*2); dfs(u*2+1);
        for(int i = 0; i <= x; i++){
            for(int j = 0; j <= i; j++){
                leftdp[u][i] = max(leftdp[u][i],min(dp[u*2][i-j],(1+j)*(1+j)));
            }
        }
        for(int i = 0; i <= x; i++){
            for(int j = 0; j <= i; j++){
                rightdp[u][i] = max(rightdp[u][i],min(dp[u*2+1][i-j],(1+j)*(1+j)));
            }
        }
        for(int i = 0; i <= x; i++){
            for(int j = 0; j <= i; j++){
                dp[u][i] = max(dp[u][i], leftdp[u][j] + rightdp[u][i-j]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    getline(cin,s);
    cin >> x;
    bld(1);
    dfs(1);
    cout << dp[1][x] << '\n';
}

