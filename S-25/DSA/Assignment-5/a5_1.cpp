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
        // adj[b].push_back(a);
    }
    vector <int> indegree(n+1,0);
    for(int i=1;i<=n;i++){
        for(int k:adj[i]){
            indegree[k]++;
        }
    }
    // queue <int> pq;
    priority_queue <int,vector<int>,greater<int>> pq;
    vector <int> pathlenght(n+1,0);
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            pq.push(i);
            pathlenght[i]=0;
        }
    }
    vector <int> rank(n+1,0);
    int cr=1; 
    while(!pq.empty()){
        // int node = pq.front();
        int node = pq.top();
        pq.pop();
        // cout<<node<<" ";
        rank[node]=cr++;
        for(int it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                pq.push(it);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << rank[i] << " ";
    }
    cout<<endl;
}