#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 150005;
int n,m,q,sq,l[mxN],a[mxN],start[400][mxN],total[400],nxt[400][mxN],pre[mxN],id[mxN],d[mxN];
vector<int>line[mxN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    sq = sqrt(n);
    for(int i = 1; i <= n; i++){
        cin >> l[i];
        line[l[i]].push_back(i);
        start[i/sq][l[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        total[i/sq]+=a[i];
    }
    for(int i = 1; i <= m; i++){
        int sz = line[i].size();
        for(int j = 0; j < sz; j++){
            id[line[i][j]] = j;
            nxt[line[i][j]/sq][i] = line[i][(j+1)%sz]/sq;
            pre[line[i][j]] = line[i][((j-1)+sz)%sz];
        }
    }
    while(q--){
        int op; cin >> op;
        if(op==1){
            int l1,r; cin >> l1 >> r;
            int blockl = (l1-1)/sq+1, blockr = r/sq, ans = 0;
            if(blockl<blockr){
                for(int i = blockl; i < blockr; i++) ans+=total[i];
                for(int i = l1; i < blockl*sq; i++){
                    int sz = line[l[i]].size();
                    ans += a[line[l[i]][(id[i]-d[l[i]]+sz)%sz]];
                }
                for(int i = blockr*sq; i <= r; i++){
                    int sz = line[l[i]].size();
                    ans += a[line[l[i]][(id[i]-d[l[i]]+sz)%sz]];
                }
            }
            else{
                for(int i = l1; i <= r; i++){
                    int sz = line[l[i]].size();
                    ans += a[line[l[i]][(id[i]-d[l[i]]+sz)%sz]];
                }
            }
            cout << ans << '\n';
        }
        else{
            int x; cin >> x;
            d[x]++;
            if(d[x]==line[x].size()) d[x]=0;
            for(int i = line[x][0]/sq; ;){
                total[nxt[i][x]]+=a[start[i][x]];
                total[i]-=a[start[i][x]];
                start[i][x] = pre[start[i][x]];
                i = nxt[i][x];
                if(i==line[x][0]/sq) break;
            }
        }
    }
}