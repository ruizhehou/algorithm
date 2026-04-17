//
// Created by houruizhe on 2021/1/29.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

//class Solution {
//private:
//    static constexpr int dirs[4][2] = {{-1, 0},
//                                       {0,  1},
//                                       {1,  0},
//                                       {0,  -1}};
//public:
//    int minimumEffortPath(vector<vector<int>> &heights) {
//        int m = heights.size();
//        int n = heights[0].size();
//        int left = 0, right = 999999, ans = 0;
//        while (left <= right) {
//            int mid = left + ((right - left) >> 1);
//            queue<pair<int, int>> q;
//            q.emplace(0, 0);
//            vector<int> seen(m * n);
//            seen[0] = 1;
//            while (!q.empty()) {
//                auto[x, y] = q.front();
//                q.pop();
//                for (auto dir : dirs) {
//                    int nx = x + dir[0];
//                    int ny = y + dir[1];
//                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx * n + ny] &&
//                        abs(heights[x][y] - heights[nx][ny]) <= mid) {
//                        q.emplace(nx, ny);
//                        seen[nx * n + ny] = 1;
//                    }
//                }
//            }
//            if (seen[m * n - 1]) {
//                ans = mid;
//                right = mid - 1;
//            } else {
//                left = mid + 1;
//            }
//        }
//        return ans;
//    }
//};

class UF {
public:
    vector<int> fa;
    vector<int> sz;
    int n;
    int comp_cnt;

public:
    explicit UF(int _n) : n(_n), comp_cnt(_n), fa(_n), sz(_n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int find_set(int x) {
        return fa[x] == x ? x : fa[x] = find_set(fa[x]);
    }

    void unite(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        if (x == y) {
            return;
        }
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        --comp_cnt;
    }

    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

struct Edge {
    int x, y, z;

    Edge(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}

    bool operator<(const Edge &that) const {
        return z < that.z;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<Edge> edges;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int id = i * n + j;
                if (i > 0) {
                    edges.emplace_back(id - n, id, abs(heights[i][j] - heights[i - 1][j]));
                }
                if (j > 0) {
                    edges.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j - 1]));
                }
            }
        }
        sort(edges.begin(), edges.end());
        UF uf(m * n);
        for (const auto &edge : edges) {
            uf.unite(edge.x, edge.y);
            if (uf.connected(0, m * n - 1)) {
                return edge.z;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> h1 = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << sol.minimumEffortPath(h1) << endl; // 2
    vector<vector<int>> h2 = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    cout << sol.minimumEffortPath(h2) << endl; // 1
    return 0;
}
