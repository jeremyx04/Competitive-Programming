#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
const int mxN = 1e5+2;
vector<pii>chu[mxN];
vector<int>vis(mxN);
vector<int>nodes;
int dist[mxN][2];

void dfs(int curr, int prev, int d, int t){
    nodes.push_back(curr);
    vis[curr]=1;
    dist[curr][t]=d;
    for(pii next : chu[curr]){
        if(next.f==prev)
            continue;
        dfs(next.f,curr,d+next.s,t);
    }
}
int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    for(int i = 0; i < M; i++){
        chu[A[i]].push_back({B[i],T[i]});
        chu[B[i]].push_back({A[i],T[i]});
    }
    int ans = 0;
    vector<int>answer;
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            dfs(i,-1,0,0);
            int u = i;
            for(int n : nodes){
                if(dist[n][0]>dist[u][0])
                    u=n;
            }
            nodes.clear();
            dfs(u,-1,0,0);
            int v = u;
            for(int n : nodes){
                if(dist[n][0]>dist[v][0])
                    v=n;
            }
            nodes.clear();
            dfs(v,-1,0,1);
            int temp = 1e9;
            for(int n : nodes)
                temp = min(temp,max(dist[n][0],dist[n][1]));
            answer.push_back(temp);
            ans = max(ans,dist[u][1]);
            nodes.clear();
        } 
    }
    sort(answer.begin(),answer.end(),greater<int>());
    if(answer.size()>=2)
        ans = max(ans,answer[0]+answer[1]+L);
    if(answer.size()>=3)
        ans = max(ans,answer[1]+answer[2]+2*L);
    return ans;       
}

/*
int main(){
    int a[] = {0, 8, 2, 5, 5, 1, 1, 10};
    int b[] = {8, 2, 7, 11, 1, 3, 9, 6};
    int c[] = {4, 2, 4, 3, 7, 1, 5, 3};
    cout << travelTime(12,8,2,a,b,c);
}
*/