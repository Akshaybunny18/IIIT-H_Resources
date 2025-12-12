#include <bits/stdc++.h>
using namespace std;

void df(vector<vector<int>> &ad, vector<int> &vi, int no, vector<int> &co, vector<vector<long long>> &cs, int c1, int c2, int c3, long long &tc, int &id) {
    vi[no] = 1;
    co[no] = (id % 3 == 0) ? c1 : (id % 3 == 1) ? c2 : c3;
    tc += cs[no - 1][co[no] - 1];
    id++;
    for (int ne : ad[no]) {
        if (!vi[ne])
            df(ad, vi, ne, co, cs, c1, c2, c3, tc, id);
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    vector<vector<long long>> c(n, vector<long long>(3, 0));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++)
            cin >> c[j][i];
    vector<int> vi(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, ve;
        cin >> u >> ve;
        v[u].push_back(ve);
        v[ve].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (v[i].size() > 2) {
            cout << -1 << "\n";
            return 0;
        }
    }
    int st = 1;
    for (int i = 1; i <= n; i++) {
        if (v[i].size() == 1) {
            st = i;
            break;
        }
    }
    vector<int> bc(n + 1);
    long long mc = LLONG_MAX;
    vector<vector<int>> coo = {
        {1, 2, 3}, {1, 3, 2}, {2, 1, 3},
        {2, 3, 1}, {3, 1, 2}, {3, 2, 1}
    };
    for (auto &co : coo) {
        vector<int> tc(n + 1, 0);
        fill(vi.begin(), vi.end(), 0);
        long long tcost = 0;
        int id = 0;
        df(v, vi, st, tc, c, co[0], co[1], co[2], tcost, id);
        if (tcost < mc) {
            mc = tcost;
            bc = tc;
        } else if (tcost == mc) {
            bool update = false;
            for (int i = 1; i <= n; i++) {
                if (tc[i] < bc[i]) { update = true; break; }
                else if (tc[i] > bc[i]) break;
            }
            if (update) bc = tc;
        }
    }
    cout << mc << "\n";
    for (int i = 1; i <= n; i++)
        cout << bc[i] << " ";
    cout << "\n";
    return 0;
}