#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    queue<pair<int, int>> q;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    vector<int> dirs = {-1, 0, 1, 0, -1};
    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        int x = front.first, y = front.second;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dirs[k], ny = y + dirs[k + 1];
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> result = updateMatrix(mat);
    for (const auto& row : result) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    return 0;
}
