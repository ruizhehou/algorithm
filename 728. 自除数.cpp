//
// Created by Ruizhe Hou on 2020/10/10.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            bool is_self_divided = true;
            int tmp = i, digit;
            while (tmp) {
                digit = tmp % 10;
                if (!digit || i % digit) {
                    is_self_divided = false;
                    break;
                }
                tmp /= 10;
            }
            if (is_self_divided) res.push_back(i);
        }
        return res;
    }
};

int main() {
    Solution sol;
    auto res = sol.selfDividingNumbers(1, 22);
    for (int v : res) cout << v << " ";
    cout << endl; // 1 2 3 4 5 6 7 8 9 11 12 15 22
    return 0;
}