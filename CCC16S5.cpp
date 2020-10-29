#include<bits/stdc++.h>
using namespace std;
#define dlwlrma ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define f first 
#define s second

const int mxN = 1e5+2, LOG = 50;
int n,b[mxN],c[mxN]; ll t;
char a[mxN];
//C1[i]=C[i-1]^C[i+1]
//C2[i]=C1[i-1]^C1[i+1]=(C[i-2]^C[i])^(C[i]^C[i+2])=C[i-2]^C[i+2]
//C3[i]=C2[i-1]^C2[i+1]=(C[i-3]^C[i+1])^(C[i-1]^C[i+3])
//C4[i]=C3[i-1]^C3[i+1]=(C[i-4]^C[i])^(C[i-2]^C[i+2])^(C[i-2]^C[i+2])^(C[i]^C[i+4])=(C[i-4]^C[i+4])
int main(){
    dlwlrma
    cin >> n >> t;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        c[i]=a[i]-'0';
    for(int i = 0; i <= LOG; i++){
        if((t>>i)&1){
            ll res = (1LL << i)%n;
            for(int j = 0; j < n; j++)
                b[j]=c[(j+(n-res)%n)%n]^c[(j+res)%n];
            memcpy(c,b,sizeof(c));
        }
    }
    for(int i = 0; i < n; i++)
        cout << c[i];
}