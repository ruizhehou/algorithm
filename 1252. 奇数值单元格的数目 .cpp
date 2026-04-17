//
// Created by Ruizhe Hou on 2020/10/8.
//
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>> &indices) {
        int rows[n];
        int cols[m];
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        for (auto indice : indices) {
            rows[indice[0]]++;
            cols[indice[1]]++;
        }
        int odd_rows = 0, odd_cols = 0;
        for (int row : rows) {
            if (row & 1) odd_rows++;
        }
        for (int col : cols) {
            if (col & 1) odd_cols++;
        }
        return odd_rows * (m - odd_cols) + (n - odd_rows) * odd_cols;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> indices1 = {{0, 1}, {1, 1}};
    cout << sol.oddCells(2, 3, indices1) << endl; // 6
    vector<vector<int>> indices2 = {{1, 1}, {0, 0}};
    cout << sol.oddCells(2, 2, indices2) << endl; // 0
    return 0;
}
