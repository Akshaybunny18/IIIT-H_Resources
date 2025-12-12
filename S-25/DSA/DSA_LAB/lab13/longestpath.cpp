#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[b].push_back(a);
    }
    vector <int> indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto k:adj[i]){
            indegree[k]++;
        }
    }
    queue <int> q;
    vector <int> pathlenght(n,0);
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
            pathlenght[i]=0;
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adj[node]){
            pathlenght[it]=pathlenght[node]+1;//max(pathlenght[it],pathlenght[node]+1);  
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    for(auto it:pathlenght){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}