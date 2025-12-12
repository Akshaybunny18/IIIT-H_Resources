#include <bits/stdc++.h>
using namespace std;


int main(){
    int m,n,k;
    cin>>n>>m>>k;
    vector <vector<pair<int,int>>> adj(n+1); 
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    vector <pair<int,int>> newedges;
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        newedges.push_back({a,b});
    }
    priority_queue<pair<long long int , int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
    vector <long long int> dist(n+1,LLONG_MAX);
    vector <bool> visited(n+1,false);
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty()){
        auto ti = pq.top();
        pq.pop();
        int node = ti.second;
        long long int d = ti.first;
        // if(visited[node]) continue;
        visited[node]=true;
        for(auto it:adj[node]){
            int ne = it.first;
            long long int wt = it.second;
            // if(!visited[ne])
            {
                if(dist[ne] > dist[node] + wt){
                    dist[ne] = dist[node] + wt;
                    pq.push({dist[ne], ne});
                }
            }
        }
    }
    int dispropose=0;
    vector <int> flag(n+1,0);
    for(auto [x,y] : newedges){
        if(dist[x]<=y) dispropose++;
        else if(y<dist[x] && flag[x]){
            dispropose++;
            // call dijkstra aftere adding newedge [1,x];
        }
        else if(y<dist[x] && !flag[x]){
            // call dijkstra aftere adding newedge [1,x];
        }
    }
    cout<<dispropose;
}