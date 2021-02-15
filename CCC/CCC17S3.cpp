#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int>miku(2005);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        miku[x]++;
    }
    vector<int>yotsuba(4005);
    for(int i = 1; i <= 2000; i++){
        if(miku[i]){
            for(int j = i; j <= 2000; j++){
                if(i==j){
                    yotsuba[i+j] += (miku[i])/2;
                }
                else{
                    yotsuba[i+j] += min(miku[i],miku[j]);
                }
            }
        }
    }
    int ans = 0, num = 0;
    for(int i = 1; i <= 4000; i++){
        if(yotsuba[i]>ans){
            ans = yotsuba[i];
            num = 0;
        }
        if(yotsuba[i]==ans) num++;
    }
    cout << ans << ' ' << num << '\n';
}