#include <bits/stdc++.h>
using namespace std;

int n, temp;

void dfsd(vector<int> adj[], int k, vector<int> &visited,int depth,int parent) {
    visited[k] = true;
    for (int x : adj[k]) {
        if (!visited[x]) {
               dfsd(adj, x, visited,depth+1,k);
        }
        else if (x!=parent) {
        
             cout << "YES";
            exit(0);
        }
    }
}

void dfs(vector<int> adj[]) {
    vector<int> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if(!visited[i])
        {
        temp = i;
        dfsd(adj, i, visited,0,-1);
}    }
}

int main() {
    int m;
    cin >> n >> m;
    vector<int> adj[n + 1]; // 1-indexed

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(adj);
    cout << "NO";
    return 0;
}