#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector <vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector <bool> visited(n+1,false);
    vector <int> dist(n+1,INT_MAX);
    vector <int> paths(n+1,0);
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[1]=0;
    paths[1]=1;
    pq.push({0,1});
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node]=true;
        for(int ne:adj[node]){
            if(dist[ne]>dist[node]+1){
                dist[ne]=dist[node]+1;
                paths[ne]=paths[node];
                pq.push({dist[ne],ne});
                paths[ne]%=(int)(1e9+7);
            } else if(dist[ne]==dist[node]+1){
                paths[ne]+=paths[node];
                paths[ne]%=(int)(1e9+7);
            }
        }
    }
    cout<<paths[n]<<endl;
}