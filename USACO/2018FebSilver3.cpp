#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

int main(){
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int n;
    cin >> n;
    map<int,int>slope;
    ll cur_val = 0;
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        cur_val += abs(a-b);
        if(abs(a) > abs(a-b)) continue; //going from a to 0 takes too long 
        slope[b] += 2; //changes from decreasing to increasing
        if(a>=0&&a<b){
            //b-a < a + y - b ->  b+b-a-a < y 
            slope[2*a]--; slope[b+b-a-a]--;
        }
        //same case as above but negative
        if(a<0&&a>b){
            slope[2*a]--; slope[b+b-a-a]--;
        }
        if(a>=0&&a>b){
            slope[2*b]--; slope[0]--;
        }
        if(a<0&&a<b){
            slope[2*b]--; slope[0]--;
        }
    }
    //find minimum value of function
    ll cur_slope = 0, ans = cur_val, oldx = 0;
    for(auto m : slope){
        int x = m.first; 
        cur_val += (x - oldx) * cur_slope;
        cur_slope += m.second;
        oldx = x;
        ans = min(ans,cur_val);
    }
    cout << ans << '\n';
}

