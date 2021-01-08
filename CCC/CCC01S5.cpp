#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 50;
int n,m; 
string a[mxN],b[mxN];
vector<int>ans;
bool found = 0;
void rec(string A, string B, int x){
    //cout << A << " " << B << '\n';
    A = A + a[x]; B = B + b[x];
    int i = 0;  
    for(; i < min(A.size(),B.size()); i++){
        if(A[i]!=B[i]) break;
    } 
    A = A.substr(i); B = B.substr(i);
    if(A.size()&&B.size()) return;
    if(ans.size()>=m) 
        return; 
    if(A.size()==0&&B.size()==0){
        found = 1;
        return;
    }
    for(int i = 1; i <= n && !found; i++){
        ans.push_back(i);
        rec(A,B,i);
        if(found) break;
        ans.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++){
        ans.push_back(i);
        rec("","",i);
        if(found) break;
        ans.pop_back();
    }   
    if(ans.size()==0){
        cout << "No solution.\n";
        return 0;
    }
    cout << ans.size() << '\n';
    for(int &x:ans){
        cout << x << '\n';
    }
}

