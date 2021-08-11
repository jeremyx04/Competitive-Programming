#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 2e5+10,seed[2]={31,43},MOD[2] = {1000000007, 998244353};
string s1,s2;
ll hsh[2][mxN],p[2][mxN];
int fn[26],fh[26];
bool cmp(){
    for(int i = 0; i < 26; i++)
        if(fn[i]!=fh[i]) return 0;
    return 1;
}
pair<ll,ll> substrhash(int l, int r){
    return (make_pair((hsh[0][r]-(hsh[0][l-1]*p[0][r-l+1])%MOD[0]+MOD[0])%MOD[0],(hsh[1][r]-(hsh[1][l-1]*p[1][r-l+1])%MOD[1]+MOD[1])%MOD[1]));
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s1 >> s2;
    p[0][0]=p[1][0]=1LL;
    for(int i = 0; i < 2; i++){
        for(int j = 1; j <= s2.size(); j++){
            hsh[i][j] = (hsh[i][j-1]*seed[i]+(s2[j-1]-'a'))%MOD[i];
            p[i][j] = (p[i][j-1]*seed[i])%MOD[i]; 
        }
    }
    set<pair<ll,ll>>st;
    for(int i = 1; i <= s1.size(); i++)
        fn[s1[i-1]-'a']++;
    for(int i = 1; i <= s2.size(); i++){
        fh[s2[i-1]-'a']++;
        if(i>s1.size())fh[s2[i-s1.size()-1]-'a']--;
        if(cmp()) st.insert(substrhash(i-s1.size()+1,i));
    }
    cout << st.size() << '\n';
}