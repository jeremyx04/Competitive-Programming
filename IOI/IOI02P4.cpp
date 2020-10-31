#include<bits/stdc++.h>
using namespace std;
#define dlwlrma ios::sync_with_stdio(0); cin.tie(0);
const int mxN = 1e4+2;
int n,s,pfT[mxN],pfF[mxN],dp[mxN],t[mxN],f[mxN];

double calc(int i, int j){
    return ((double)(dp[i]-dp[j])/(double)(pfT[i]-pfT[j]));
}
int main(){
    dlwlrma
    cin >> n >> s;
    pfT[n] = pfF[n] = 0;
    for(int i = 0; i < n; i++)
        cin >> t[i] >> f[i];
    for(int i = n-1; i >= 0; i--){
        pfT[i] = pfT[i+1]+t[i];
        pfF[i] = pfF[i+1]+f[i];
    }
    deque<int>dq;
    dq.push_back(n);
    for(int i = n-1; i >= 0; i--){
        while(dq.size() >= 2 && calc(dq[0],dq[1]) < pfF[i])
            dq.pop_front(); 
        int c = dq.front();
        dp[i] = dp[c] + (s+pfT[i]-pfT[c])*pfF[i];
        while(dq.size()>=2 && calc(dq[dq.size()-2],dq[dq.size()-1]) > calc(dq[dq.size()-1],i))
            dq.pop_back();
        dq.push_back(i);
    }
    cout << dp[0] << "\n";
}