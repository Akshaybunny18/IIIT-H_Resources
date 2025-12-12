#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector <pair<int, int>>> &adj, vector<bool>&visited,int node){
    visited[node] = true;
    cout<<node<<" ";
    for(auto it:adj[node]){
        int ne = it.first;
        if(!visited[ne]){
            dfs(adj,visited,ne);
        }
    }
}


void bfs(vector <vector <pair<int,int>>> &adj,int start){
    int v = adj.size();
    vector <bool> visited(v,false);
    queue <int> q;
    visited[start]=true;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it:adj[node]){
            int ne = it.first;
            if(!visited[ne]){
                visited[ne]=true;
                q.push(ne);
            }
        }
    }
    cout<<endl;
}

void dijkstra(priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> &pq, vector<int> &dist, vector<bool> &visited,vector<vector<pair<int, int>>> &adj,int start){
    for(int i=1;i<dist.size();i++){
        dist[i] = INT_MAX;
    }
    visited.resize(adj.size(), false);
    visited[start] = true;
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        for(auto it:adj[node]){
            int ne = it.first;
            int wt = it.second;
            if(!visited[ne]){
                if(dist[ne] > dist[node] + wt){
                    dist[ne] = dist[node] + wt;
                    pq.push({dist[ne], ne});
                }
            }
        }
    }
}
 
int pareent(vector <int> parent, int node){
    if(parent[node] == node) return node;
    return parent[node] = pareent(parent, parent[node]);
}
void raank(vector <int> &rank, vector <int> &parent, vector<vector<pair<int, int>>> &adj,vector<pair<int, int>> &edges){
    int v = adj.size();
    for(int i=0;i<v;i++){
        parent[i] = i;
        rank[i] = 0;
    }
    for(auto it:edges){
        int a = it.first;
        int b = it.second;
        int parentA = pareent(parent, a);
        int parentB = pareent(parent, b);
        if(parentA != parentB){
            if(rank[parentA] < rank[parentB]){
                parent[parentA] = parentB;
            } else if(rank[parentA] > rank[parentB]){
                parent[parentB] = parentA;
            } else {
                parent[parentA] = parentB;
                rank[parentB]++;
            }
        }
    }
}

void kruskal(vector<vector<pair<int, int>>> &adj, vector<pair<int,pair<int, int>>> &edges,vector<pair<int, pair<int, int>>> &mst){
    int v = adj.size();
    sort(edges.begin(), edges.end());
    vector <int> parent(v,0);
    vector <int> rank(v,0);
    for(int i=0;i<v;i++){
        parent[i] = i;
        rank[i] = 0;
    }
    // rank(parent, rank, adj, edges);

    
}


void topologicalsort(vector<vector<int>> &adj,vector <int> &pathlenght){
    int v = adj.size();
    vector <int> indegree(v,0);
    for(int i=0;i<v;i++){
        for(int k:adj[i]){
            indegree[k]++;
        }
    }
    priority_queue <int,vector<int>,greater<int>> pq;
    // vector <int> pathlenght(v,0);
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            pq.push(i);
            pathlenght[i]=0;
        }
    }
    while(!pq.empty()){
        int node = pq.top();
        pq.pop();
        cout<<node<<" ";
        for(int it:adj[node]){
            indegree[it]--;
            pathlenght[it]=/*pathlenght[node]+1;*/max(pathlenght[it],pathlenght[node]+1);
            if(indegree[it]==0){
                pq.push(it);
            }
        }
    }
    cout<<endl;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int, int>>> adj(n+1);
    vector <bool> visited(n+1, false);
    vector <int> pathlenght(n+1,0);
    vector <int> parent(n+1,0);
    vector <int> rank(n+1,0);
    vector <pair<int, pair<int, int>>> edges;
    vector <pair<int, pair<int, int>>> mst;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        edges.push_back({c,{a,b}});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
    vector<int> dist(n+1, INT_MAX);
    int start = 1;
    dijkstra(pq,dist,visited,adj,start);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}