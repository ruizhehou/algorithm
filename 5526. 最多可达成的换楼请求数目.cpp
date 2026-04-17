//
// Created by Ruizhe Hou on 2020/9/27.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int tot[25];
public:
    int maximumRequests(int n, vector<vector<int>> &req) {
        int ans = 0;
        int m = req.size();
        int lim = (1 << m) - 1;
        for (int i = 1; i <= lim; ++i) {
            for (int j = 0; j < n; ++j) tot[j] = 0;
            int cnt = 0;
            for (int j = 0, k = 1; j < m; ++j, k <<= 1)
                if (i & k) {
                    ++tot[req[j][1]], --tot[req[j][0]];
                    ++cnt;
                }
            bool flag = true;
            for (int j = 0; j < n; ++j) {
                if (tot[j] != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans = max(ans, cnt);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> req1 = {{0, 1}, {1, 0}, {0, 1}, {1, 2}, {2, 0}, {3, 4}};
    cout << sol.maximumRequests(5, req1) << endl; // 5
    vector<vector<int>> req2 = {{0, 0}, {1, 2}, {2, 1}};
    cout << sol.maximumRequests(3, req2) << endl; // 3
    return 0;
}