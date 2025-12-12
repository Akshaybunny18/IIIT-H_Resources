#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector <priority_queue<int, vector<int>, greater<int>>> &pq, vector <bool> &visited){
    visited[node]=true;
    cout<<node<<" ";
    while(!pq[node].empty()){
        int ne = pq[node].top();
        pq[node].pop();
        if(!visited[ne]){
            dfs(ne,pq,visited);
        }
    }
}

void bfs(int node, vector <priority_queue<int, vector<int>, greater<int>>> &pq, vector <bool> &visited){
    priority_queue<int, vector<int>, greater<int>> q;
    visited[node]=true;
    q.push(node);
    while(!q.empty()){
        int curr = q.top();
        q.pop();
        cout<<curr<<" ";
        while(!pq[curr].empty()){
            int ne = pq[curr].top();
            pq[curr].pop();
            if(!visited[ne]){
                visited[ne]=true;
                q.push(ne);
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector <priority_queue<int, vector<int>, greater<int>>> pq(n+1);
    vector <bool> visited(n+1, false);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        pq[a].push(b);
        pq[b].push(a);
    }
    // dfs(1, pq, visited);
    bfs(1, pq, visited);
    // cout<<endl;
    return 0;
}
