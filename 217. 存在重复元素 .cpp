//
// Created by houruizhe on 2020/10/19.
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (s.count(num)) return true;
            s.insert(num);
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> n1 = {1, 2, 3, 1};
    cout << sol.containsDuplicate(n1) << endl; // 1
    vector<int> n2 = {1, 2, 3, 4};
    cout << sol.containsDuplicate(n2) << endl; // 0
    return 0;
}