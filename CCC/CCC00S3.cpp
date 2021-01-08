#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<string>miku[n+1];
    vector<string>urls(n);
    cin.ignore();
    unordered_map<string,int> mp;
    for(int i = 0; i < n; i++){
        string s;
        getline(cin,s);
        mp[s] = i+1;
        urls[i] = s;
        while(s!="</HTML>"){
            getline(cin,s);
            if(s.size()<8) continue;
            for(int j = 0; j < s.size()-8; j++){  
                if(s.substr(j,8)=="<A HREF="){
                    if(s[j+8]=='"'){
                        string url = "";
                        bool ok = 0;
                        for(int k = j+9; k < s.size(); k++){
                            if(s[k]=='"'){
                                ok = 1; 
                                break;
                            }
                            url = url + s[k];
                        }
                        if(ok)
                            miku[i+1].push_back(url);
                    }
                }
            }
        }
    }
    vector<int>adj[n+1];
    for(int i = 0; i < n; i++){
        for(auto &s : miku[mp[urls[i]]]){
            cout << "Link from " << urls[i] << " to " << s << '\n';
            if(mp[s])
                adj[mp[urls[i]]].push_back(mp[s]);
        }
    }
    bool vis[n];
    while(true){
        string s1,s2;
        getline(cin,s1);
        if(s1=="The End") break;
        getline(cin,s2);
        if(!mp[s1]||!mp[s2]){
            cout << "Can't surf from " << s1 << " to " << s2 << ".\n";
            continue;
        }
        queue<int>q;
        ms(vis,0);
        q.push(mp[s1]);
        vis[mp[s1]] = 1;
        while(!q.empty()){
            int c = q.front(); q.pop();
            for(auto &x : adj[c]){
                if(!vis[x]){
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        if(vis[mp[s2]]){
            cout << "Can surf from " << s1 << " to " << s2 << ".\n";
        }
        else{
            cout << "Can't surf from " << s1 << " to " << s2 << ".\n";
        }
    }
}