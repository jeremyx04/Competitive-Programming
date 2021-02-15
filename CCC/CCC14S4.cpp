#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

struct miku{
    int x,y1,y2,t;
    bool operator < (const miku &m) const{
        return x<m.x;
    }
};
const int mxN = 2004;
int N,T;
vector<miku>nino;
vector<int>yotsuba;
unordered_map<int,int>mp;
ll sweep[mxN],ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> T;
    for(int i = 0; i < N; i++){
        int x,y,xx,yy,t; cin >> x >> y >> xx >> yy >> t;
        yotsuba.push_back(y);
        yotsuba.push_back(yy);
        nino.push_back({x,y,yy,t});
        nino.push_back({xx,y,yy,-t});
    }
    sort(all(nino));
    sort(all(yotsuba));
    yotsuba.erase(unique(all(yotsuba)),yotsuba.end());
    for(int i = 0; i < yotsuba.size(); i++){
        mp[yotsuba[i]] = i;
    }
    for(int i = 0; i < nino.size(); i++){
        for(int j = mp[nino[i].y1]; j < mp[nino[i].y2]; j++) 
            sweep[j] += nino[i].t;
        for(int j = 0; j < yotsuba.size(); j++)
            if(sweep[j] >= T) ans += (ll) (nino[i+1].x - nino[i].x) * (yotsuba[j+1] - yotsuba[j]);
    }
    cout << ans << '\n';
}

