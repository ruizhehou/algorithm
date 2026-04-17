//
// Created by Ruizhe Hou on 2020/10/10.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if (n & 1) {
            res.push_back(0);
        }
        int start = 1;
        for (; n > 1; n -= 2, start++) {
            res.push_back(start);
            res.push_back(-start);
        }
        return res;
    }
};

int main() {
    Solution sol;
    auto r1 = sol.sumZero(5);
    for (int v : r1) cout << v << " ";
    cout << endl;
    auto r2 = sol.sumZero(3);
    for (int v : r2) cout << v << " ";
    cout << endl;
    return 0;
}