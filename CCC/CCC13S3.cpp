#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

int t,ans;
vector<pair<int,int>>match;
void rec(int g,vector<int>games){
    if(g==6){
        vector<int>scores(4);
        for(int i = 0; i < 6; i++){
            if(games[i]==1){
                scores[match[i].first]+=3;
            }
            else if(games[i]==2){
                scores[match[i].first]++; scores[match[i].second]++;
            }
            else{
                scores[match[i].second]+=3;
            }
        }
        for(int i = 0; i < 4; i++){
            if(scores[i] >= scores[t] && i != t) return;
        }
        ans++; return;
    }
    for(int i = 0; i < 6; i++){
        if(!games[i]){
            games[i] = 1;
            rec(g+1,games);
            games[i] = 2;
            rec(g+1,games);
            games[i] = 3;
            rec(g+1,games);
            break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int g;
    cin >> t >> g;
    --t;
    for(int i = 0; i < 4; i++){
        for(int j = i+1; j < 4; j++){
            match.push_back({i,j});
        }
    }
    vector<int>games(6); //1 = win, 2 = tie, 3 = lose 
    for(int i = 0; i < g; i++){
        int a,b,sa,sb;
        cin >> a >> b >> sa >> sb;
        --a; --b;
        int tmp = -1;
        for(int j = 0; j < 6; j++)
            if(match[j].first==a&&match[j].second==b) tmp = j;
        if(sa>sb) games[tmp] = 1;
        else if(sb>sa) games[tmp] = 3;
        else games[tmp] = 2;
    }
    rec(g,games);
    cout << ans << '\n';
}

