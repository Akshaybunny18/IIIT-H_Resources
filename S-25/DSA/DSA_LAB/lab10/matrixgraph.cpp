#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Use vector instead of VLAs
    vector<vector<int>> a(n + 1, vector<int>(m));  
    vector<vector<int>> list(n + 1, vector<int>(n + 1, 0));  
    vector<int> co(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int c = -1, d = -1;
        for (int j = 1; j <= n; j++) {
            if (a[j][i] == -1) c = j;
            if (a[j][i] == 1) d = j;
            if (c != -1 && d != -1) break;
        }
        if (c != -1 && d != -1) {
            list[c][d] = -1;
            list[d][c] = -1;
            co[c]++;
            co[d]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        list[i][i] = co[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << list[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
