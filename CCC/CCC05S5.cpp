#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 1e5+5;
int n,tree[mxN];
pair<ll,int>score[mxN];
void upd(int x, int v){
    for( ; x < mxN; x+=x&-x)
        tree[x]+=v;
}
int qry(int x){
    int res = 0;
    for(; x > 0; x-=x&-x)
        res+=tree[x];
    return res;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> score[i].first;
        score[i].second = i;
    }
    sort(score+1,score+1+n,greater<pair<int,int>>());
    ll ans = 0;
    for(int i = 1; i <= n; i++){ 
        upd(score[i].second,1);
        ans += qry(score[i].second);
    }
    cout << fixed << setprecision(2) << (double)ans/n << '\n';
}

 