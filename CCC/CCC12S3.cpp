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
    vector<int>miku(n);
    vector<pair<int,int>>freq(1005);
    for(int i = 0; i < 1005; i++)
        freq[i].second = i;
    for(int &i : miku){
        cin >> i; freq[i].first++;
    }
    sort(all(freq));
    vector<int>a;
    int tmp = freq[1004].first, i = 1004;
    while(i >= 0 && freq[i].first == tmp){
        a.push_back(freq[i].second);
        i--;
    }
    vector<int>b;
    tmp = freq[i].first;
    while(i >= 0 && freq[i].first == tmp){
        b.push_back(freq[i].second);
        i--;
    }
    sort(all(b)); sort(all(a));
    if(a.size()>=2){
        cout << a[a.size()-1] - a[0] << '\n';
        return 0;
    }
    cout << max(abs(a[0] - b[b.size()-1]),abs(a[a.size()-1]-b[0])) << '\n';
}