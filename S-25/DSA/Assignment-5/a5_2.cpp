#include <bits/stdc++.h>
using namespace std;

int findparent(vector <int> &parent,int k){
    if(parent[k]==k){
        return k;
    }
    return parent[k]=findparent(parent,parent[k]);
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,int>> adj(n);
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[i]={x,y,z};
    }

    vector <tuple<int,int,int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto [x1, y1, z1] = adj[i];
            auto [x2, y2, z2] = adj[j];
            int cost = min({abs(x1 - x2), abs(y1 - y2), abs(z1 - z2)});
            edges.push_back({cost,i, j});
        }
    }

    for (int i = 0; i < m; i++) {
        int u=-1, v=-1;
        cin >> u >> v;
        u-=1; v-=1; 
        edges.push_back({0,u, v});
    }
    
    priority_queue<
    tuple<int, int, int>,
    vector<tuple<int , int, int>>,
    greater<>
    > pq;

    for (const auto& [w,u, v] : edges) {
        pq.push({w, u, v});
    }

    vector <int> parent(n) ,size(n,1);
    for(int i=0;i<n;i++) parent[i]=i;
    long long toti=0;
    int aa=0;
    while(!pq.empty() && aa<n-1){
        auto [w,u,v] = pq.top();
        pq.pop();
        int ultimatep_u = findparent(parent, u);
        int ultimatep_v = findparent(parent, v);
        if (ultimatep_u != ultimatep_v) {
            toti+=w;
            aa++;
            // if(ultimatep_u!=ultimatep_v) continue;
            if(size[ultimatep_u]<size[ultimatep_v]){
                parent[ultimatep_u]=ultimatep_v;
                size[ultimatep_v]+=size[ultimatep_u];
            }
            else{
                parent[ultimatep_v]=ultimatep_u;
                size[ultimatep_u]+=size[ultimatep_v];
            }
        }
    }

    cout<<toti<<endl;
    return 0;
}




#include <bits/stdc++.h>
using namespace std;

int findparent(vector<int>& parent, int k) {
    if (parent[k] == k) {
        return k;
    }
    return parent[k] = findparent(parent, parent[k]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> adj(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[i] = {x, y, z};
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> edges;

    for (int dim = 0; dim < 3; dim++) {
        vector<pair<int, int>> temp;  

        for (int i = 0; i < n; i++) {
            int val = (dim == 0 ? get<0>(adj[i]) : (dim == 1 ? get<1>(adj[i]) : get<2>(adj[i])));
            temp.push_back({val, i});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap(temp.begin(), temp.end());

        int prevIdx = heap.top().second;
        heap.pop();
        while (!heap.empty()) {
            int curIdx = heap.top().second;
            heap.pop();
            auto [x1, y1, z1] = adj[prevIdx];
            auto [x2, y2, z2] = adj[curIdx];
            int cost = min({abs(x1 - x2), abs(y1 - y2), abs(z1 - z2)});
            edges.push({cost, prevIdx, curIdx});
            prevIdx = curIdx;
        }
    }

    for (int i = 0; i < m; i++) {
        int u=-1, v=-1;
        cin >> u >> v;
        u-=1; v-=1;
        edges.push({0, u, v});
    }

    vector<int> parent(n), size(n, 1);
    for(int i=0;i<n;i++) parent[i]=i;
    long long toti = 0;
    int aa = 0;

    while (!edges.empty() && aa < n - 1) {
        auto [w, u, v] = edges.top();
        edges.pop();

        int ultimatep_u = findparent(parent, u);
        int ultimatep_v = findparent(parent, v);
        if (ultimatep_u != ultimatep_v) {
            toti += w;
            aa++;
            // if(ultimatep_u!=ultimatep_v) continue;
            if (size[ultimatep_u] < size[ultimatep_v]) {
                parent[ultimatep_u] = ultimatep_v;
                size[ultimatep_v] += size[ultimatep_u];
            } else {
                parent[ultimatep_v] = ultimatep_u;
                size[ultimatep_u] += size[ultimatep_v];
            }
        }
    }

    cout << toti << endl;
    return 0;
}
