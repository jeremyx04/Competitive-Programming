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
    int ans = 0;
    while(n>1){
        int i = 2;
        for(; i <= sqrt(n); i++)
            if(n%i==0) break;
        if(n%i==0){
            int t = n/i;
            n -= t;
            ans += n/t;
        }
        else{
            n--;
            ans+=n;
        }
    }
    cout << ans << '\n';
}