//
// Created by Ruizhe Hou on 2020/9/25.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
        int n = quiet.size();
        vector<vector<int>> g(n); // 有向图，富的指向穷的
        vector<int> indegree(n, 0); // 入度
        for (auto &r : richer) {
            g[r[0]].push_back(r[1]);
            indegree[r[1]]++;
        }
        queue<int> q; // 点的id
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
            ans[i] = i; // 初始化最安静的人是自己
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                // 最富的人，入度为0
            }
        }
        while (!q.empty()) {
            int id = q.front(); // 人的id
            int q_val = quiet[ans[id]];
            q.pop();
            for (auto nt : g[id]) { // 跟他连接的人，比他穷
                if (q_val < quiet[ans[nt]])
                    ans[nt] = ans[id];
                if (--indegree[nt] == 0)
                    q.push(nt);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> richer = {{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}};
    vector<int> quiet = {3, 2, 5, 4, 6, 1, 7, 0};
    auto res = sol.loudAndRich(richer, quiet);
    for (int v : res) cout << v << " ";
    cout << endl; // 5 5 2 5 4 5 6 7
    return 0;
}
