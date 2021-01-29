#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 105;
struct edge{
    int u,v,w;
    bool operator < (const edge &e) const{
        return w<e.w;
    }
};
int n,par[mxN];
map<pair<int,int>,pair<int,vector<int>>>mp;
vector<edge>yotsuba;
int find(int x){
    if(x!=par[x])
        return par[x] = find(par[x]);
    return par[x];
}
bool merge(int a, int b){
    a = find(a); b = find(b);
    if(a==b) return false;
    par[a] = b;
    return true;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int e; cin >> e; 
        vector<int>miku(e);
        for(int j = 0; j < e; j++)
            cin >> miku[j];
        for(int j = 0; j < e; j++){
            int w; cin >> w;
            mp[make_pair(min(miku[j],miku[(j+1)%e]),max(miku[j],miku[(j+1)%e]))].first = w;
            mp[make_pair(min(miku[j],miku[(j+1)%e]),max(miku[j],miku[(j+1)%e]))].second.push_back(i);
        }
    }
    vector<pair<int,pair<int,int>>>nino;
    for(auto &x : mp){
        if(x.second.second.size()==1) nino.push_back(make_pair(x.second.first,make_pair(x.second.second[0],n)));
        else nino.push_back(make_pair(x.second.first,make_pair(x.second.second[0],x.second.second[1])));
    }
    sort(all(nino));
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < mxN; i++)
        par[i] = i;
    for(auto &x : nino){
        if(x.second.second==n) continue;
        if(merge(x.second.first,x.second.second))
            ans1 += x.first; 
    }
    for(int i = 0; i < mxN; i++)
        par[i] = i;
    for(auto &x : nino){
        if(merge(x.second.first,x.second.second))
            ans2 += x.first;
    }
    cout << min(ans1,ans2) << '\n';
}

