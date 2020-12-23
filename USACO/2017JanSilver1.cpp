#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

int n,t;
vector<int>d;
int check(int k){
    if(k>=n){
        return *max_element(all(d));
    }
    priority_queue<int>pq;
    for(int i = 0; i < k; i++)
        pq.push(-d[i]);
    int ret = 0;
    for(int i = k; i < n; i++){
        int c = -pq.top();
        pq.pop();
        pq.push(-(c+d[i]));
    }
    while(!pq.empty()){
        ret = (int)-pq.top();
        pq.pop();
    }
    return ret;
}
int main(){
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    cin >> n >> t;
    d.resize(n);
    for(int i = 0; i < n; i++)
        cin >> d[i];
    int lb = 1, rb = n;
    while(lb<=rb){
        int mb = (lb+rb)/2; //k = mb
        if(check(mb)>t) 
            lb = mb+1;
        else 
            rb = mb-1;
    }
    cout << lb << '\n';
}

