#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

int h,k;
vector<int>miku;

bool check(int x){
    int ret = h;
    for(int i = 0; i < h && miku[i] <= miku[0]+2*x; i++){
        int cnt = 1, lst = miku[0]+2*x;
        for(int j = i+1; j < h && miku[j] + 2*x - 1e6 < miku[i]; j++){
            if(miku[j] > lst){
                lst = miku[j] + 2*x;
                cnt++;
            }
        }
        ret = min(ret,cnt);
    }
    return ret <= k;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> h;
    miku.resize(h);
    for(int i = 0; i < h; i++){
        cin >> miku[i];
    }
    sort(all(miku));
    cin >> k;
    int lb = 0, rb = 1e6+1;
    while(lb<=rb){
        int mb = (lb+rb)/2;
        if(check(mb))
            rb = mb-1;
        else
            lb = mb+1;
    }
    cout << lb << '\n';
}
