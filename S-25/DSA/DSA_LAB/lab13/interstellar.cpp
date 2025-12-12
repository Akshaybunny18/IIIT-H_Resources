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
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int j=1;j<=t;j++){
        int n,m;
        cin>>n>>m;
        vector <vector<int>> adj(n+1);
        vector <pair<int,int>> edges(1);
        vector <int> mark(m+1,0);
        stack <int> s;
        vector<int> parent (n+1,0);
        for(int i=1;i<=n;i++) parent[i]=i;
        vector<int> si(n+1,1);
        vector <long long> ans;
        long long totalDisconnected = 1;
        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            edges.push_back({a,b});
        }
        int queries;
        cin>>queries;
        // set<int> roots;
        for(int i=1;i<=queries;i++){
            char c;
            cin>>c;
            if(c=='Q'){
                s.push(-1);
            }            
            else if(c=='R'){
                int e;
                cin>>e;
                s.push(e);
                mark[e]=1;
            }
        }
        for(int i=1;i<=m;i++){
            if(!mark[i]){
                auto hi = edges[i];
                int x=hi.second;
                int y=hi.first;
                int px=findparent(parent,x);
                int py=findparent(parent,y);
                if(si[px]>si[py]){
                    si[px]+=si[py];
                    parent[py]=px;
                }
                else{
                    si[py]+=si[px];
                    parent[px]=py;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(parent[i]=i){ 
                totalDisconnected*=si[i]; // so no need of taking n*(n-1)2
            }
        }
        while(!s.empty()){
            int k = s.top(); 
            s.pop();
            if(k==-1){
                ans.push_back(totalDisconnected);
            }
            else{
                auto hi = edges[k];
                int x=hi.second;
                int y=hi.first;
                int px=findparent(parent,x);
                int py=findparent(parent,y);
                if(px!=py){
                    totalDisconnected-= (long long)si[px]*si[py];
                    if(si[px]>si[py]){
                        si[px]+=si[py];
                        parent[py]=px;
                        // roots.erase(py);
                    }
                    else{
                        si[py]+=si[px];
                        parent[px]=py;
                        // roots.erase(px);
                    }
                }
            }
        }
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int findparent(vector<int>& parent, int k) {
    return parent[k] == k ? k : parent[k] = findparent(parent, parent[k]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int j = 1; j <= t; j++) {
        int n;
        cin >> n;
        int m = n - 1;
        vector<vector<int>> adj(n + 1);
        vector<pair<int,int>> edges(1);
        vector<int> mark(m + 1, 0);
        stack<int> s;
        vector<int> parent(n + 1), si(n + 1, 1);
        vector<long long> ans;
        long long totalDisconnected = (long long)n * (n - 1) / 2;

        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            edges.push_back({a, b});
        }

        int queries;
        cin >> queries;
        for (int i = 1; i <= queries; i++) {
            char c;
            cin >> c;
            if (c == 'Q') {
                s.push(-1);
            } else {
                int e;
                cin >> e;
                s.push(e);
                mark[e] = 1;
            }
        }

        for (int i = 1; i <= n; i++) parent[i] = i;
        for (int i = 1; i <= m; i++) {
            if (!mark[i]) {
                int x = edges[i].first;
                int y = edges[i].second;
                int px = findparent(parent, x);
                int py = findparent(parent, y);
                if (px != py) {
                    totalDisconnected -= (long long)si[px] * si[py];
                    if (si[px] < si[py]) swap(px, py);
                    parent[py] = px;
                    si[px] += si[py];
                }
            }
        }

        while (!s.empty()) {
            int k = s.top();
            s.pop();
            if (k == -1) {
                ans.push_back(totalDisconnected);
            } else {
                int x = edges[k].first;
                int y = edges[k].second;
                int px = findparent(parent, x);
                int py = findparent(parent, y);
                if (px != py) {
                    totalDisconnected -= (long long)si[px] * si[py];
                    if (si[px] < si[py]) swap(px, py);
                    parent[py] = px;
                    si[px] += si[py];
                }
            }
        }

        for (int i = (int)ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}
