#include <bits/stdc++.h>
using namespace std;

int dxDFS[] = {0, 0, 1, -1}, dyDFS[] = {1, -1, 0, 0};

void dfs(int x, int y, int n, int m, int val, int label,
    vector<vector<int>>& v, vector<vector<int>>& region) {
    stack<pair<int, int>> st;
    st.push({x, y});
    region[x][y] = label;
    while (!st.empty()) {
        auto [cx, cy] = st.top(); st.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = cx + dxDFS[d], ny = cy + dyDFS[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                if (v[nx][ny] == val && region[nx][ny] == -1) {
                    region[nx][ny] = label;
                    st.push({nx, ny});
                }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) cin >> v[i][j];

        vector<vector<int>> region(n, vector<int>(m, -1));
        vector<int> region_value;
        int id = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (region[i][j] == -1) {
                    dfs(i, j, n, m, v[i][j], id, v, region);
                    region_value.push_back(v[i][j]);
                    ++id;
                }

        // Optimized adjacency list (vector instead of unordered_set)
        vector<vector<int>> adj(id);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int u = region[i][j];
                if (j + 1 < m) {
                    int v_ = region[i][j+1];
                    if (u != v_) {
                        adj[u].push_back(v_);
                        adj[v_].push_back(u);
                    }
                }
                if (i + 1 < n) {
                    int v_ = region[i+1][j];
                    if (u != v_) {
                        adj[u].push_back(v_);
                        adj[v_].push_back(u);
                    }
                }
            }
        }

        // Remove duplicates (faster than unordered_set)
        for (int i = 0; i < id; ++i) {
            sort(adj[i].begin(), adj[i].end());
            adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
        }

        int src = region[0][0], dest = region[n - 1][m - 1];
        vector<int> dist(id, -1);
        deque<int> dq;
        dq.push_front(src);
        dist[src] = 0;

        while (!dq.empty()) {
            int u = dq.front(); dq.pop_front();
            for (int v_ : adj[u]) {
                int cost = (region_value[u] == region_value[v_]) ? 0 : 1;
                if (dist[v_] == -1 || dist[v_] > dist[u] + cost) {
                    dist[v_] = dist[u] + cost;
                    if (cost == 0) dq.push_front(v_);
                    else dq.push_back(v_);
                }
            }
        }
        cout << dist[dest] << "\n";
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];

        const int INF = INT_MAX;
        vector<vector<int>> dist(n, vector<int>(m, INF));

        deque<pair<int, int>> dq;
        dist[0][0] = 0;
        dq.push_back({0, 0});

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while(!dq.empty()){
            auto [x, y] = dq.front();
            dq.pop_front();
            for (int d = 0; d < 4; d++){
                int nx = x + dx[d], ny = y + dy[d];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                int cost = (grid[nx][ny] == grid[x][y]) ? 0 : 1;
                if(dist[nx][ny] > dist[x][y] + cost){
                    dist[nx][ny] = dist[x][y] + cost;
                    if(cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        cout << dist[n - 1][m - 1] << "\n";
    }
    return 0;
}