#include <bits/stdc++.h>
using namespace std;



void addedge(vector<vector<int>> &v,int src,int des){
    v[src].push_back(des);
    v[des].push_back(src);
}

void dfs(vector <vector<int>> &adj,vector<bool>&visited,int node){
    visited[node]=true;
    cout<<node<<" ";
    for(int ne:adj[node]){
        if(!visited[ne]){
            dfs(adj,visited,ne);
        }
    }
}

void DFSIterative(const vector<vector<int>> &adj, int start) {
    int V = adj.size();
    vector<bool> visited(V, false);
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            // Push neighbors in reverse order to maintain natural order
            for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
                if (!visited[*it]) {
                    st.push(*it);
                }
            }
        }
    }
    cout << endl;
}

void dfsstart(vector <vector<int>> &adj,int start){
    int v = adj.size();
    vector <bool> visited(v,false);
    dfs(adj,visited,start);
    cout<<endl;
} 



void bfs(vector <vector<int>> &adj,int start){
    int v = adj.size();
    vector <bool> visited(v,false);
    queue <int> q;
    visited[start]=true;
    q.push(start);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for(int ne:adj[temp]){
            if(!visited[ne]){
                visited[ne]=true;
                q.push(ne);
            }
        }
    }
    cout<<endl;
}

bool isbipartite(vector <vector<int>> &adj){
    int v=adj.size();
    vector <int> color(v,-1);
    for (int i=0;i<v;i++){
        if(color[i]==-1){
            queue <int> q;
            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                for(int ne:adj[node]){
                    if(color[ne]==-1){
                        color[ne]=1-color[node];
                        q.push(ne);
                    } else
                    if(color[ne]==color[node]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void print_alledges(vector <vector<int>> &adj){
    for(int i=0;i<adj.size();i++){
        cout<<i<<"->";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

void print_allbridges(vector <vector<int>> &adj){
    int v = adj.size();
    vector <int> disc(v,-1);
    vector <int> low(v,-1);
    vector <bool> visited(v,false);
    vector <pair<int,int>> bridges;
    int time=0;
    
    function<void(int,int)> dfs = [&](int node,int parent){
        visited[node]=true;
        disc[node]=low[node]=time++;
        
        for(int ne:adj[node]){
            if(ne==parent) continue;
            if(!visited[ne]){
                dfs(ne,node);
                low[node]=min(low[node],low[ne]);
                if(low[ne]>disc[node]){
                    bridges.push_back({node,ne});
                }
            } else {
                low[node]=min(low[node],disc[ne]);
            }
        }
    };
    
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,-1);
        }
    }
    
    for(auto it:bridges){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

int no_of_provinces(vector <vector<int>> &adj){
    int v = adj.size();
    int pro=0;
    vector <bool> visited(v,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            pro++;
            dfs(adj,visited,i);
        }
    }
    return pro;
}


int main() {
	int n;
	cin>> n;
	vector <vector<int>> adj(n);
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
	    int src,des;
	    cin>>src>>des;
	    addedge(adj,src,des);
	}
    vector<bool> visited(n, false);
    vector <int > distances(n,INT_MAX);
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int start=1;
    distances[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node]=true;
        cout<<node<<" ";
        for(int ne:adj[node]){
            if(!visited[ne]){
                distances[ne]=min(distances[ne],distances[node]+1);// push only if diatances are updated
                if(distances[ne]==distances[node]+1){
                    pq.push({distances[ne],ne});
                }
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" "<<distances[i]<<endl;
    }
    
}
