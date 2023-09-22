#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> minDistance(n, vector<int>(m, INT_MAX));
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            } else {
                vis[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        minDistance[row][col] = steps;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                if (vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }
    }
    return minDistance;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    vector<vector<int>> minDistances = updateMatrix(grid);

    for (const auto& row : minDistances) {
        for (int dist : row) {
            cout << dist << "\t";
        }
        cout << endl;
    }

    return 0;
}

