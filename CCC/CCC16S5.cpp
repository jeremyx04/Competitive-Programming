#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 1e5+5;
int n;
ll t;
bool a[mxN],b[mxN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        if(c=='1') a[i]=1;
    }
    for(int i = 50; i >= 0; i--){
        if((t>>i)&1){
            ll tmp = (1LL << i)%n;
            for(int j = 0; j < n; j++){
                b[j] = a[((j+n-tmp)%n)%n]^a[(j+tmp)%n];
            }
            for(int j = 0; j < n; j++)
                a[j] = b[j];
        }
    }
    for(int i = 0; i < n; i++)
        cout << a[i];
}