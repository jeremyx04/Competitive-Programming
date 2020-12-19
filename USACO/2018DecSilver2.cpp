#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 1e5+5;

int N;
pair<int,int>p[mxN];
bool cmp(pair<int,int>a, pair<int,int>b){
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}
int main(){
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;   
    for(int i = 1; i <= N; i++){ 
        cin >> p[i].first >> p[i].second;
    }
    vector<pair<int,int>>miku;
    for(int i = 1; i <= N; i++){
        int l = p[i].first-p[i].second;
        int r = p[i].first+p[i].second;
        miku.push_back({l,r});
    }
    sort(miku.begin(),miku.end(),cmp);
    int ans = 0, mxr = 0;
    for(int i = 0; i < N; i++){
        if(miku[i].second<=mxr){
            ans++;
        }
        else{
            mxr = miku[i].second;
        }
    }
    cout << N-ans << '\n';
}

