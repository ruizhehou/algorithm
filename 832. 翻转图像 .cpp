//
// Created by Ruizhe Hou on 2020/10/8.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
        for (auto &vec : A) {
            reverse(vec.begin(), vec.end());
            for (auto &elm : vec) {
                elm = 1 - elm;
            }
        }
        return A;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> img = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    auto res = sol.flipAndInvertImage(img);
    for (auto &row : res) {
        for (int v : row) cout << v << " ";
        cout << endl;
    }
    // 0 0 1
    // 0 1 0
    // 1 1 1
    return 0;
}
