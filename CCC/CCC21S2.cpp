#include<bits/stdc++.h>
using namespace std;

int n,m,k,numR,numC,ans,row[5000005],col[5000005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        char in; 
        int x; 
        cin >> in >> x;
        if(in=='R'){
            numR++;
            if(row[x]){
                ans+=(2*numC-m);
                numR-=2;
                row[x]=0;
            }
            else{
                ans+=(m-2*numC);
                row[x]=1;
            }
        }
        if(in=='C'){
            numC++;
            if(col[x]){
                ans+=(2*numR-n);
                numC-=2;
                col[x]=0;
            }
            else{
                ans+=(n-2*numR);
                col[x]=1;
            }
        }
    }
    cout << ans << '\n';
}