#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<int>h(n+1),w(n);
    for(int i = 0; i <= n; i++){
        cin >> h[i];
    }
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    double area = 0;
    for(int i = 0; i < n; i++){
        area += (double) w[i] * (h[i+1]+h[i]);
    }
    cout << area/2 << '\n';
}