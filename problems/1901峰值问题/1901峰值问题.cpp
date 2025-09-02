#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

pair<int, int> findPeakBFS(const vector<vector<int>>& mat) {
    if (mat.empty()) return {-1, -1};

    int m = mat.size(), n = mat[0].size();
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    auto isValid = [&](int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    };

    auto isPeak = [&](int x, int y) {
        for (auto& dir : dirs) {
            int nx = x + dir.first, ny = y + dir.second;
            if (isValid(nx, ny) && mat[x][y] < mat[nx][ny]) {
                return false;
            }
        }
        return true;
    };

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if (isPeak(cur.first, cur.second)) {
            return {cur.first, cur.second};
        }

        int x = cur.first, y = cur.second;
        pair<int, int> nextMove = {x, y};
        int nextVal = mat[x][y];

        for (auto& dir : dirs) {
            int nx = x + dir.first, ny = y + dir.second;
            if (isValid(nx, ny) && mat[nx][ny] > nextVal) {
                nextVal = mat[nx][ny];
                nextMove = {nx, ny};
            }
        }

        q.push(nextMove);
    }

    return {-1, -1};  // 如果没有找到峰值
}

int main() {
    vector<vector<int>> mat = {
        {1, 4},
        {3, 2}
    };

    pair<int, int> apair = findPeakBFS(mat);
    auto x = apair.first;
    auto y = apair.second;
    cout << "Peak found at: (" << x << ", " << y << ")" << endl;

    return 0;
}
